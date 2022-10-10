#include <cmath>

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
