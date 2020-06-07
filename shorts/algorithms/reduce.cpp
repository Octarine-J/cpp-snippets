#include <algorithm>
#include <numeric>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

TEST_CASE( "Sum" ) {
    std::vector<int> v = {1, 5, 3, 7};

    int sum = std::accumulate(v.begin(), v.end(), 0);

    REQUIRE( sum == 16 );
}

TEST_CASE( "Product" ) {
    std::vector<int> v = {1, 5, 3, 7};

    int product = std::accumulate(v.begin(), v.end(), 1, [](int x, int y) {
        return x * y;
    });

    REQUIRE( product == 105 );

    // can use a functor instead of a lambda
    // can omit template parameter to be inferred based on the identity type (1 vs 1.0)
    int product2 = std::accumulate(v.begin(), v.end(), 1, std::multiplies<>());

    REQUIRE( product2 == 105 );
}

TEST_CASE( "And" ) {
    std::vector<bool> v = {true, true, true};

    auto my_and = [](const std::vector<bool>& v) {
        return std::accumulate(v.begin(), v.end(), true, std::logical_and<>());
    };

    REQUIRE( my_and(v) == true );

    v.push_back(false);

    REQUIRE( my_and(v) == false );
}

TEST_CASE( "And (using a Standard Algorithm" ) {
    std::vector<int> v = {2, 4, 6, 8};

    bool all_even = std::all_of(v.begin(), v.end(), [](int value) {
        return value % 2 == 0;
    });

    REQUIRE( all_even );
}

TEST_CASE( "Or (using a Standard Algorithm" ) {
    std::vector<int> v = {1, 4, 3, 7};

    bool has_even = std::any_of(v.begin(), v.end(), [](int value) {
        return value % 2 == 0;
    });

    REQUIRE( has_even );
}
