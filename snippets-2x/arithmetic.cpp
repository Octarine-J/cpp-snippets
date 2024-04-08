#include <numbers>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Predefined Numbers" ) {
    // from C++20
    REQUIRE( (std::numbers::pi - 3.1415926 < 1e-7) );
    REQUIRE( (std::numbers::e - 2.718 < 1e-3) );
    REQUIRE( (std::numbers::sqrt2 - 1.41 < 1e-2) );
}
