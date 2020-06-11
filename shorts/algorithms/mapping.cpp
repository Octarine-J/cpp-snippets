#include <algorithm>
#include <execution>
#include <numeric>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

TEST_CASE( "Transform (.map)" ) {
    std::vector<int> v = {1, 2, 3, 4, 5};

    std::transform(v.begin(), v.end(), v.begin(), [](int value) {
        return value * 2;
    });

    REQUIRE ( v == std::vector<int>{2, 4, 6, 8, 10} );
}

TEST_CASE( "Erase (.filter)" ) {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // remove-erase-idiom
    auto it = std::remove_if(v.begin(), v.end(), [](int value) {
        return value % 2 == 1; 
    });

    v.erase(it, v.end());

    REQUIRE( v == std::vector<int>{2, 4} );
}

TEST_CASE( "CopyIf (.filter)" ) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> result(v.size());

    auto end_pos = std::copy_if(v.begin(), v.end(), result.begin(), [](int value) {
        return value % 2 == 1;
    });

    result.erase(end_pos, result.end());

    REQUIRE ( result == std::vector<int>{1, 3, 5} );
}

TEST_CASE( "Partition" ) {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // reorders the elements so that the elements satisfying the preficate
    // go in the beginning, followed by the elements that do not satisfy the predicate 
    auto it = std::partition(v.begin(), v.end(), [](int value) {
        return value % 2 == 0;
    });

    REQUIRE( it - v.begin() == 2 );
    REQUIRE( v[0] % 2 == 0 );
    REQUIRE( v[1] % 2 == 0 );
    REQUIRE( v[2] % 2 == 1 );
    REQUIRE( v[3] % 2 == 1 );
    REQUIRE( v[4] % 2 == 1 );
}

TEST_CASE( "Sorting" ) {
    std::vector<int> v = {6, 2, 3, 7, 4, 5, 1};

    std::sort(v.begin(), v.end(), std::greater<>());

    REQUIRE( v == std::vector<int>{7, 6, 5, 4, 3, 2, 1} );
}


TEST_CASE( "Sorting (Parallel)" ) {
    std::vector<int> v = {6, 2, 3, 7, 4, 5, 1};

    std::sort(std::execution::par, v.begin(), v.end());

    REQUIRE( v == std::vector<int>{1, 2, 3, 4, 5, 6, 7} );
}

TEST_CASE( "Merge Two Sorted Vectors in O(n)" ) {
    std::vector<int> a = {2, 4, 6};
    std::vector<int> b = {1, 3, 5};

    std::vector<int> result(a.size() + b.size());

    std::merge(a.begin(), a.end(), b.begin(), b.end(), result.begin());

    REQUIRE( result == std::vector<int>{1, 2, 3, 4, 5, 6} );
}