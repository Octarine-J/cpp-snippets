#include <string>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Struct Designated Initializers" ) {
    // must not have a constructor
    struct Employee {
        std::string name;
        int id;
        int age;
        int salary = 1000;
    };

    // C++20: aggregate initialization ("builder" style)
    Employee e {
        .name = "Helga",
        .age = 23,
        // field 'id' gets zero value
        // field 'salary' gets the default value
    };

    REQUIRE( e.name == "Helga" );
    REQUIRE( e.age == 23 );
    REQUIRE( e.id == 0 );
    REQUIRE( e.salary == 1000 );
}
