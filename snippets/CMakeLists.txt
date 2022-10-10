cmake_minimum_required(VERSION 3.20)
project(snippets)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

set(SOURCES
        containers/any.cpp
        containers/bitset.cpp
        containers/deque.cpp
        containers/list.cpp containers/map.cpp containers/multimap.cpp containers/priority_queue.cpp containers/set.cpp numbers/arithmetic.cpp strings/regex.cpp containers/vector.cpp std_algorithms/search.cpp std_algorithms/generate.cpp std_algorithms/mapping.cpp)

add_executable(all-tests ${SOURCES})
target_link_libraries(all-tests PRIVATE Catch2::Catch2WithMain)
