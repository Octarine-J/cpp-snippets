#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Variable Definition" ) {
    // different ways to initialize an integer
    int a1 = 0;
    int a2 = {0};  // {} checks that value fits!
    int a3 {0};     // same
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
