add_rules("mode.debug", "mode.release")

-- add_cxxflags("clang::-stdlib=libc++")

set_languages("c++latest")

target("mod")
    set_kind("static")
    add_files("src1/*.cpp", "src1/*.mpp")

target("test")
    set_kind("binary")
    add_files("test/*.cpp")
    add_deps("mod")