#include <cmath>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Rounding" ) {
    REQUIRE( static_cast<int>(std::round(5.5)) == 6 );
    REQUIRE( static_cast<int>(std::ceil(5.5)) == 6 );
    REQUIRE( static_cast<int>(std::floor(5.5)) == 5 );
}

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

TEST_CASE( "Float Cannot Hold All Int" ) {
    int x = 1'000'000'160;
    float y = x;  // narrowing conversion
    int z = y;

    REQUIRE( z == 1'000'000'128 );
}
