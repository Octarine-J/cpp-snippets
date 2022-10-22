#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Struct Initialization Pitfalls" ) {
    static auto count = 0u;

    struct TestStruct {
        int value;

        // structs can also have a constructor
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
    REQUIRE( count == 2);  // no constructor is called due to the bug above
}

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

TEST_CASE( "Structured Bindings for Structs" ) {
    struct Employee {
        std::string name;
        int age;
    };

    Employee employee { "Helga", 33 };

    // structured binding
    auto [name, age] = employee;

    REQUIRE( name == "Helga" );
    REQUIRE( age == 33 );
}
