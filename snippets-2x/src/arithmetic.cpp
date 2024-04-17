#include <compare>
#include <numbers>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Predefined Numbers" ) {
    // from C++20
    REQUIRE( (std::numbers::pi - 3.1415926 < 1e-7) );
    REQUIRE( (std::numbers::e - 2.718 < 1e-3) );
    REQUIRE( (std::numbers::sqrt2 - 1.41 < 1e-2) );
}

TEST_CASE( "Spaceship Operator" ) {
    int i = 42;
    std::strong_ordering res = i <=> 0;

    REQUIRE( res == std::strong_ordering::greater );
    REQUIRE( std::is_gt(res) );

    // only partial ordering is defined for double
    // i.e. exist x, y such that !(x < y) && !(y < x)
    double a = std::numeric_limits<double>::infinity();
    double b = std::numeric_limits<double>::quiet_NaN();
    std::partial_ordering res_double = a <=> b;

    REQUIRE( res_double == std::partial_ordering::unordered );
}
