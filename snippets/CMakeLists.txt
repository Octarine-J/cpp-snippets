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
        object_oriented/structs.cpp
        strings/regex.cpp
        container_algorithms/generate.cpp
        container_algorithms/search.cpp
        container_algorithms/mapping.cpp
        container_algorithms/reduce.cpp
        strings/c_string.cpp
        strings/char.cpp
        strings/string.cpp
        strings/string_conversion.cpp
        strings/string_view.cpp
        strings/stringstream.cpp
        object_oriented/classes_inheritance.cpp
        object_oriented/friends.cpp
        object_oriented/operator_overloading.cpp
        object_oriented/classes.cpp
        pointers/function_pointers.cpp
        pointers/pointers.cpp
        pointers/references.cpp
        pointers/smart_pointers.cpp
        core_language/control_statements.cpp
        functional/functions.cpp
        object_oriented/enums.cpp
        core_language/attributes.cpp
        core_language/namespaces.cpp
        core_language/assert.cpp
        streams/bidirectional_stream.cpp
        streams/stream_positioning.cpp
        object_oriented/classes_ref_methods.cpp
        core_language/cast.cpp
        streams/streams.cpp
        streams/input_stream.cpp
        streams/stream_modifiers.cpp
        streams/stream_low_level.cpp
        templates/concepts.cpp
        numbers/time_duration.cpp
        functional/lambda.cpp
        functional/functor.cpp
        templates/templates.cpp templates/if_constexpr.cpp templates/concepts_custom.cpp templates/templates_class.cpp templates/templates_variadic.cpp streams/file_stream.cpp system/files.cpp container_algorithms/container_algorithms.cpp)

add_executable(all-tests ${SOURCES})
target_link_libraries(all-tests PRIVATE Catch2::Catch2WithMain)
