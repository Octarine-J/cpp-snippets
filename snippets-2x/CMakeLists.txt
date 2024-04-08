cmake_minimum_required(VERSION 3.20)
project(snippets-2x)

set(CMAKE_CXX_STANDARD 20)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

set(SOURCES
        arithmetic.cpp
        cast.cpp
        concepts.cpp
        concepts_custom.cpp
        functions.cpp
        structs.cpp
)

add_executable(all-tests ${SOURCES})
target_link_libraries(all-tests PRIVATE Catch2::Catch2WithMain)
