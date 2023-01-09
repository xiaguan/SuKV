set_project("SuKV")

add_rules("mode.debug", "mode.release")

set_languages("c++23")


target("SkipList")
    set_kind("static")
    add_files("src/*.cpp", "src/*.mpp")

target("SkipListTest")
    set_kind("binary")
    add_files("test/skiplist_test.cpp")
    add_deps("SkipList")