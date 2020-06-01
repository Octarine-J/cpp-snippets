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
}
