#include <catch2/catch_test_macros.hpp>

// C++20
TEST_CASE( "For Loop with Initializer" ) {
    for (auto v = {1, 2, 3}; auto value : v) {
        REQUIRE( value <= 3 );
    }
}
