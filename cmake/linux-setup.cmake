set(CMAKE_CXX_STANDARD 20)
set(UNIT_TEST ON)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_GENERATOR "Unix Makefiles")
add_compile_options(-Wall -Wextra
        $<$<STREQUAL:CMAKE_BUILD_TYPE,"Debug">:-g>
        $<$<STREQUAL:CMAKE_BUILD_TYPE,"Release">:-O3>)