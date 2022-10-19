#include <cmath>
#include <numbers>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Infinity" ) {
    double x = std::numeric_limits<double>::infinity();
    REQUIRE( std::isinf(x) );

    double a = 100.;
    double b = 0.;
    REQUIRE( std::isinf(a / b) );
}

TEST_CASE( "Not a Number" ) {
    double a = 0.;
    double b = 0.;
    REQUIRE( std::isnan(a / b) );
}

TEST_CASE( "Predefined Numbers" ) {
    // from C++20
    REQUIRE( (std::numbers::pi - 3.1415926 < 1e-7) );
    REQUIRE( (std::numbers::e - 2.718 < 1e-3) );
    REQUIRE( (std::numbers::sqrt2 - 1.41 < 1e-2) );
}
