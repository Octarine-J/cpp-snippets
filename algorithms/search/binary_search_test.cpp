#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include "../../apps/datagen/include/random.hpp"
#include "binary_search.hpp"

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

TEST_CASE( "Binary Search - Empty" ) {
    std::vector<int> v;

    auto it = alg::binary_search(4, v.begin(), v.end());

    REQUIRE( it == v.end() );
}

TEST_CASE( "Binary Search - Singleton" ) {
    std::vector<int> v = {3};

    // not found
    auto it = alg::binary_search(5, v.begin(), v.end());
    REQUIRE( it == v.end() );

    // found
    it = alg::binary_search(3, v.begin(), v.end());
    REQUIRE( it == v.begin() );
}

TEST_CASE( "Binary Search - Two Items" ) {
    std::vector<int> v = {3, 4};

    // not found
    auto it = alg::binary_search(5, v.begin(), v.end());
    REQUIRE( it == v.end() );

    // found 3
    it = alg::binary_search(3, v.begin(), v.end());
    REQUIRE( it == v.begin() );

    // found 4
    it = alg::binary_search(4, v.begin(), v.end());
    REQUIRE( it == v.begin() + 1);
}

TEST_CASE( "Binary Search - Random" ) {
    std::vector<int> target_index = random_int_vector(100, 0, 99);

    for (int index : target_index) {
        std::vector<int> v = random_int_vector(100, -99999, 99999);
        std::sort(v.begin(), v.end());
        int target = v[index];

        auto result = alg::binary_search(target, v.begin(), v.end());
        REQUIRE( result != v.end() );
        REQUIRE( *result == target );
    }
}
