#include <cmath>
#include "sqrt.hpp"

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

TEST_CASE( "Range" ) {
    double x = 1.0;
    do {
        REQUIRE( numeric::abs(std::sqrt(x) - numeric::sqrt(x)) < 0.01 );
        x += 0.1;
    } while (x <= 100.0);
}

TEST_CASE( "Irrational" ) {
    REQUIRE( numeric::sqrt(2.0) - 1.414 < 1e-3 );
}

TEST_CASE( "Zero" ) {
    REQUIRE( numeric::sqrt(0.0) < numeric::c_epsilon );
}
