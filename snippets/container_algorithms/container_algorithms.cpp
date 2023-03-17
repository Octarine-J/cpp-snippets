#include <algorithm>
#include <iterator>
#include <vector>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Copy Unique Elements" ) {
    std::vector<int> src {1, 2, 1, 2, 2, 3, 1};
    std::vector<int> dest;

    // first sort
    std::sort(src.begin(), src.end());
    // then copy unique
    std::unique_copy(src.begin(), src.end(), std::back_inserter(dest));

    REQUIRE( dest == std::vector {1, 2, 3} );
}
