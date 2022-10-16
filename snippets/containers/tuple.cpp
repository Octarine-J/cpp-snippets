#include <iostream>
#include <tuple>

#include <catch2/catch_test_macros.hpp>


// can be used to return multiple values from a function
std::tuple<int, std::string> foo() {
    return { 10, "ten" };  // requires C++17
}

TEST_CASE( "Create Tuple" ) {
    auto t = std::make_tuple(3, "data", true);

    // i-th field access
    REQUIRE( std::get<0>(t) == 3 );
    REQUIRE( std::get<1>(t) == std::string("data") );
    REQUIRE( std::get<2>(t) );

    // field access by type (if all types are distinct)
    REQUIRE( std::get<const char*>(t) == std::string("data") );
}

TEST_CASE( "Tuple Element Destructuring" ) {
    auto [i, s] = foo();  // C++17

    REQUIRE( i == 10 );
    REQUIRE( s == "ten" );

    // pre-C++17 method
    int value;
    std::string str;
    std::tie(value, str) = foo();
    REQUIRE( value == 10 );
    REQUIRE( str == "ten" );
}

TEST_CASE( "Compare Multiple Values" ) {
    auto t1 = std::make_tuple(1, std::string("test"));
    auto t2 = std::make_tuple(1, std::string("temp"));
    REQUIRE( t1 > t2 );  // can use normal relational operators

    // if values are not in a tuple, they still can be conveniently
    // compared with std::tie
    auto [x, s1] = t1;
    auto [y, s2] = t2;
    REQUIRE( std::tie(x, s1) > std::tie(y, s2) );
}
