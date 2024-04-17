#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Variable Init" ) {
    // different ways to initialize an integer
    int a1 = 0;
    int a2 = {0};  // {} checks that value fits!
    int a3 {0};    // same
    int a4(0);

    extern int b;  // declares, but not defines a variable
                   // no storage is allocated

    REQUIRE( a1 == 0 );
    REQUIRE( a2 == 0 );
    REQUIRE( a3 == 0 );
    REQUIRE( a4 == 0 );

    // trying to use b will result in
    // error: unresolved external symbol "int b"
}

TEST_CASE( "Integer Literals" ) {
    int i1 = 20, i2 = 024, i3 = 0x14;  // decimal, octal, hexadecimal integers
    int i4 = 0b00010100;               // C++14: binary literals

    REQUIRE(( i1 == i2 && i2 == i3 && i3 == i4 ));

    int i5 = 1'024'768;                // can separate digits with '
    REQUIRE( i5 == 1024768 );
}
