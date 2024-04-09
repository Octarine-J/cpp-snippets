cmake_minimum_required(VERSION 3.20)
project(snippets)

set(CMAKE_CXX_STANDARD 17)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

set(SOURCES
        container_algorithms/container_algorithms.cpp
        container_algorithms/generate.cpp
        container_algorithms/mapping.cpp
        container_algorithms/reduce.cpp
        container_algorithms/search.cpp
        containers/any.cpp
        containers/array.cpp
        containers/deque.cpp
        containers/bitset.cpp
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
        core_language/assert.cpp
        core_language/attributes.cpp
        core_language/cast.cpp
        core_language/control_statements.cpp
        core_language/initialization.cpp
        core_language/iterators.cpp
        core_language/namespaces.cpp
        functional/lambda.cpp
        functional/functions.cpp
        functional/functor.cpp
        multithreading/threads.cpp
        multithreading/threads_async.cpp
        multithreading/threads_future.cpp
        numbers/arithmetic.cpp
        numbers/random.cpp
        numbers/time_duration.cpp
        object_oriented/classes.cpp
        object_oriented/classes_inheritance.cpp
        object_oriented/classes_ref_methods.cpp
        object_oriented/enums.cpp
        object_oriented/friends.cpp
        object_oriented/operator_overloading.cpp
        object_oriented/structs.cpp
        pointers/function_pointers.cpp
        pointers/pointers.cpp
        pointers/references.cpp
        pointers/smart_pointers.cpp
        strings/c_string.cpp
        strings/char.cpp
        strings/regex.cpp
        strings/string.cpp
        strings/string_conversion.cpp
        strings/string_view.cpp
        strings/stringstream.cpp
        streams/bidirectional_stream.cpp
        streams/file_stream.cpp
        streams/input_stream.cpp
        streams/streams.cpp
        streams/stream_low_level.cpp
        streams/stream_modifiers.cpp
        streams/stream_positioning.cpp
        system/files.cpp
        templates/if_constexpr.cpp
        templates/templates.cpp
        templates/templates_class.cpp
        templates/templates_variadic.cpp
)

add_executable(all-tests ${SOURCES})
target_link_libraries(all-tests PRIVATE Catch2::Catch2WithMain)
