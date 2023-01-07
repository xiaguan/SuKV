import std;
import SkipList;

#include "gtest/gtest.h"

using Key = uint64_t;

struct Comparator
{
	int operator()(const Key & l , const Key & r) const
	{
		if( l < r)
		{
			return -1;
		}
		else if ( l > r)
		{
			return 1;
		}
		return 0;
	}
};


TEST(SkipTest, Empty) {
    Arena arena;
    Comparator cmp;
    SkipList<Key, Comparator> list(cmp, &arena);
    ASSERT_TRUE(!list.Contains(10));

    SkipList<Key, Comparator>::Iterator iter(&list);
    ASSERT_TRUE(!iter.Valid());
    iter.SeekToFirst();
    ASSERT_TRUE(!iter.Valid());
    iter.Seek(100);
    ASSERT_TRUE(!iter.Valid());
    iter.SeekToLast();
    ASSERT_TRUE(!iter.Valid());
}


TEST(SkipTest, InsertAndLookup) {
    const int N = 20000;
    const int R = 50000;
    Random rnd(1,R-1  );
    std::set<Key> keys;
    Arena arena;
    Comparator cmp;
    SkipList<Key, Comparator> list(cmp, &arena);

    // make sure no equal key
    for (int i = 0; i < N; i++) {
        Key key = rnd.Rand();
        if (keys.insert(i).second) {
            list.Insert(i);
        }
    }

    for (int i = 0; i < R; i++) {
        if (list.Contains(i)) {
            ASSERT_EQ(keys.count(i), 1);
        }
        else {
            ASSERT_EQ(keys.count(i), 0);
        }
    }

    // Simple iterator tests
    {
        SkipList<Key, Comparator>::Iterator iter(&list);
        ASSERT_TRUE(!iter.Valid());

        iter.Seek(0);
        ASSERT_TRUE(iter.Valid());
        ASSERT_EQ(*(keys.begin()), iter.key());

        iter.SeekToFirst();
        ASSERT_TRUE(iter.Valid());
        ASSERT_EQ(*(keys.begin()), iter.key());

        iter.SeekToLast();
        ASSERT_TRUE(iter.Valid());
        ASSERT_EQ(*(keys.rbegin()), iter.key());
    }

    // Forward iteration test
    for (int i = 0; i < R; i++) {
        SkipList<Key, Comparator>::Iterator iter(&list);
        iter.Seek(i);

        // Compare against model iterator
        std::set<Key>::iterator model_iter = keys.lower_bound(i);
        for (int j = 0; j < 3; j++) {
            if (model_iter == keys.end()) {
                ASSERT_TRUE(!iter.Valid());
                break;
            }
            else {
                ASSERT_TRUE(iter.Valid());
                ASSERT_EQ(*model_iter, iter.key());
                ++model_iter;
                iter.Next();
            }
        }
    }
}

// TODO : ADD CONCURRENCY TEST
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}