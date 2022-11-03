#include <algorithm>
#include <array>
#include <numeric>
#include <vector>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Generate" ) {
    // replaces the value in a container
    std::array<int, 5> a {};

    int x = 1;
    std::generate(a.begin(), a.end(), [&x]{
        return x *= 2;
    });

    REQUIRE( a == std::array<int, 5>{2, 4, 8, 16, 32} );
    REQUIRE( x == 32 );  // note that x changes
}

TEST_CASE( "Iota" ) {
    std::vector<char> v(5);

    std::iota(v.begin(), v.end(), 'a');

    REQUIRE( v == std::vector<char>{'a', 'b', 'c', 'd', 'e'} );
}
