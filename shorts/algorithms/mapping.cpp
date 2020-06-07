#include <algorithm>
#include <array>
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

TEST_CASE( "Generate" ) {
    // replaces the value in a container
    std::array<int, 5> a;

    int x = 1;
    std::generate(a.begin(), a.end(), [&x]{
        return x *= 2;
    });

    REQUIRE( a == std::array<int, 5>{2, 4, 8, 16, 32} );
}
