#include <any>
#include <string>
#include <variant>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Empty any" ) {
    std::any x;
    REQUIRE( ! x.has_value() );

    std::any y {"test"};
    REQUIRE( y.has_value() );
}

TEST_CASE( "Any cast" ) {
    std::any x {3};

    int value = std::any_cast<int>(x);
    REQUIRE( value == 3 );

    REQUIRE_THROWS_AS( std::any_cast<std::string>(x), std::bad_any_cast );
}

TEST_CASE( "Variant" ) {
    // variant is similar to any, but can hold only predefined types
    std::variant<int, std::string> v {42};

    REQUIRE( std::holds_alternative<int>(v) );
    REQUIRE( std::get<int>(v) == 42 );
}
