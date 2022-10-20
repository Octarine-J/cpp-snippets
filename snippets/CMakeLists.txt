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
        containers/array.cpp
        containers/bitset.cpp
        containers/deque.cpp
        containers/list.cpp
        containers/map.cpp
        containers/multimap.cpp
        containers/optional.cpp
        containers/pair.cpp
        containers/priority_queue.cpp
        containers/set.cpp
        containers/tuple.cpp
        containers/unordered_map.cpp
        containers/vector.cpp
        core_language/iterators.cpp
        multithreading/threads.cpp
        multithreading/threads_async.cpp
        multithreading/threads_future.cpp
        numbers/arithmetic.cpp
        object_oriented/struct_init.cpp
        strings/regex.cpp
        std_algorithms/generate.cpp
        std_algorithms/search.cpp
        std_algorithms/mapping.cpp
        std_algorithms/reduce.cpp
        strings/c_string.cpp
        strings/char.cpp
        strings/string.cpp
        strings/string_conversion.cpp
        strings/string_view.cpp
        strings/stringstream.cpp
        object_oriented/classes_inheritance.cpp object_oriented/friends.cpp object_oriented/operator_overloading.cpp object_oriented/classes.cpp pointers/function_pointers.cpp pointers/pointers.cpp pointers/references.cpp)

add_executable(all-tests ${SOURCES})
target_link_libraries(all-tests PRIVATE Catch2::Catch2WithMain)
