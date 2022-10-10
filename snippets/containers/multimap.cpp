#include <map>

#include <catch2/catch_test_macros.hpp>

/**
 * multimap allows storing multiple values
 * associated with the same key
 */
TEST_CASE( "MultiMap Allows Multiple Values with the Same Key" ) {
    std::multimap<int, std::string> numbers {
            {1, "one"},
            {1, "ein"},
            {2, "two"},
            {2, "zwei"}
    };

    // get all values by key
    const auto& [begin, end] = numbers.equal_range(2);

    REQUIRE( begin != end );

    for (auto it = begin; it != end; ++it) {
        REQUIRE( it->first == 2 );
        REQUIRE( (it->second == "two" or it->second == "zwei") );
    }
}
