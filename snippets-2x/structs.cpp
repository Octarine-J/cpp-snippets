#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Aggregate Initialization" ) {
    // must not have a constructor
    struct TestStruct {
        int a;
        char b = 'b';
        bool c;
    };

    // C++20: aggregate initialization ("builder" style)
    TestStruct s3 {
            .a = 10,
            .c = true  // field 'b' gets the default value
    };

    REQUIRE( s3.a == 10 );
    REQUIRE( s3.b == 'b' );
    REQUIRE( s3.c );
}
