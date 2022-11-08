#include <algorithm>
#include <iostream>
#include "count_operations.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "count_operations (instrumented)" ) {
    // generate a random vector of size n
    const size_t n = 8;
    auto v = random_double_vector(n);

    // run some code for evaluation
    count_operations(std::cout, v, [](auto begin, auto end) {
        std::sort(begin, end);
    });
}

TEST_CASE( "count_operations_n (instrumented)" ) {
    count_operations_n(std::cout, 16, 16 * 1024, [](auto begin, auto end) {
        std::sort(begin, end);
    });
}
