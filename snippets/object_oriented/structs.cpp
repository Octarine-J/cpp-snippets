#include <string>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Struct Zero Init" ) {
    struct Person {
        std::string name;
        int age;
    };

    Person p {};

    REQUIRE( p.name == "" );
    REQUIRE( p.age == 0 );
}

TEST_CASE( "Struct Init Pitfalls" ) {
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
    TestStruct s2;     // the same effect

    REQUIRE( count == 2 );
    REQUIRE( s1.value == 42 );
    REQUIRE( s2.value == 42 );

    TestStruct s3();  // beware: this actually declares a function 's3', and does not allocate an object
    REQUIRE( count == 2 );  // no constructor is called due to the bug above
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
