cmake_minimum_required(VERSION 3.20)
project(algorithms)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.0.1
)
FetchContent_MakeAvailable(Catch2)

include_directories(
        data_structures
        numeric
        optimization
        search
        sorting
)

set(SOURCES
        data_structures/binary_counter_test.cpp
        data_structures/linked_list_test.cpp
        data_structures/list_pool_test.cpp
        data_structures/matrix_test.cpp
        numeric/minmax_test.cpp
        numeric/sqrt_test.cpp
        optimization/knapsack_test.cpp
        search/binary_search_test.cpp
        sorting/sorting_test.cpp
        theory/count_operations.hpp
        theory/instrumented.cpp
        theory/instrumented_test.cpp
        #       ...
        graphs/union_find/quick_find_test.cpp graphs/union_find/quick_find.hpp graphs/union_find/quick_union.hpp graphs/union_find/quick_union_test.cpp graphs/union_find/union_find_base.hpp)

add_executable(all-tests ${SOURCES})
target_link_libraries(all-tests PRIVATE Catch2::Catch2WithMain)
