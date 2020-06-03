#include <algorithm>
#include <array>
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

TEST_CASE( "Generate" ) {
    // replaces the value in a container
    std::array<int, 5> a;

    int x = 1;
    std::generate(a.begin(), a.end(), [&x]{
        return x *= 2;
    });

    REQUIRE( a == std::array<int, 5>{2, 4, 8, 16, 32} );
}
