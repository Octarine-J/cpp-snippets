#include <any>
#include <string>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Empty any" ) {
    std::any x;
    REQUIRE( not x.has_value() );

    std::any y {"test"};
    REQUIRE( y.has_value() );
}

TEST_CASE( "Any cast" ) {
    std::any x {3};

    int value = std::any_cast<int>(x);
    REQUIRE( value == 3 );

    REQUIRE_THROWS_AS( std::any_cast<std::string>(x), std::bad_any_cast );
}
