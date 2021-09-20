#include <algorithm>
#include <vector>
#include "minmax.hpp"

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

TEST_CASE( "Empty" ) {
    std::vector<int> v;
    auto [min, max] = numerical::minmax(v.cbegin(), v.cend());

    REQUIRE( v.cend() == min );
    REQUIRE( v.cend() == max );
}

TEST_CASE( "Singleton" ) {
    std::vector<int> v {42};
    auto [min, max] = numerical::minmax(v.cbegin(), v.cend());

    REQUIRE( v.cbegin() == min );
    REQUIRE( v.cbegin() == max );
}

TEST_CASE( "CommonCase" ) {
    std::vector<std::vector<int>> vs = {
            {7, 42}, {42, 7},
            {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1},
            {1, 2, 3, 4}, {1, 4, 3, 2}, {2, 1, 4, 3}, {4, 3, 2, 1}, {2, 4, 1, 3},
            {5, 4, 3, 11, 12, 10}
    };

    for (const auto& v : vs) {
        auto [min, max] = numerical::minmax(v.cbegin(), v.cend());

        REQUIRE( std::min_element(v.cbegin(), v.cend()) == min );
        REQUIRE( std::max_element(v.cbegin(), v.cend()) == max );
    }
}
