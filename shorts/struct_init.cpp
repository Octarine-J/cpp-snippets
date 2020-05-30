#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"

TEST_CASE( "Initialization Pitfalls" ) {
    static auto count = 0u;

    struct TestStruct {
        int value;

        TestStruct() {
            value = 42;
            ++count;
        }
    };

    // call the constructor, which must initialize all data members
    TestStruct s1 {};  // does not trigger zero-init!
    TestStruct s2;  // the same effect

    REQUIRE( count == 2 );
    REQUIRE( s1.value == 42 );
    REQUIRE( s2.value == 42 );

    TestStruct s3();  // beware: this actually declares a function 's3', and does not allocate an object

    REQUIRE(2, count);  // no constructor is called due to the bug above
}
