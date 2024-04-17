#include <bit>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "bit cast" ) {
    // C++20: creates a new object from bits of other object
    // works for trivially copyable types only
    float a = 2.8f;
    int b = std::bit_cast<int>(a);

    REQUIRE( b == 1077097267 );
}
