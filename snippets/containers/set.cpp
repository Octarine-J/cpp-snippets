#include <set>
#include <vector>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Set Usage" ) {
    std::set<int> ids;

    // add a single element
    ids.insert(100);

    // see whether an element exists in the set
    REQUIRE( ids.count(100) == 1);

    // add multiple elements
    std::vector<int> digits {1, 2, 3};
    ids.insert(digits.begin(), digits.end());

    REQUIRE( ids.size() == 4 );

    // remove element from a set
    ids.erase(1);
    ids.erase(200);  // non-existing element

    REQUIRE( ids.size() == 3 );
}

TEST_CASE( "Insert an Element and Check the Result" ) {
    std::vector<int> v {1, 2, 3, 1, 3, 4};
    std::set<int> unique_values;
    std::set<int> duplicates;

    for (int value : v) {
        if (!unique_values.insert(value).second) {  // false on failure
            duplicates.insert(value);
        }
    }

    REQUIRE( unique_values == std::set<int>{1, 2, 3, 4} );
    REQUIRE( duplicates == std::set<int>{1, 3} );
}
