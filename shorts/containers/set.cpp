#include <set>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

TEST_CASE( "Set Usage" ) {
    std::set<int> ids;

    // add a single element
    ids.insert(100);

    // see whether an element exists in the set
    REQUIRE( ids.count(100) == 1);

    // add multiple elements
    std::vector<int> digits = {1, 2, 3};
    ids.insert(digits.begin(), digits.end());

    REQUIRE( ids.size() == 4 );

    // remove element from a set
    ids.erase(1);
    ids.erase(200);  // non-existing element

    REQUIRE( ids.size() == 3 );
}
