import SkipList;
import std;

#include <cstdint>

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

// TODO : ADD CONCURRENCY TEST
int main(int argc, char **argv) {
    Arena arena;
    Comparator cmp;
    SkipList<Key, Comparator> list(cmp, &arena);
    std::cout << list.Contains(10) << std::endl;
}