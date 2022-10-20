#include <iostream>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "References" ) {
    // references can replace pointers in many use cases
    // unlike pointers, references cannot be null

    int i = 17;
    int &r = i;  // reference is another name for an object

    r = 19;  // changes to a reference affect the bound object

    REQUIRE( i == 19 );
}


// rvalue references

void read_message(std::string& message) {
    std::cout << "l-value: " << message << std::endl;
}

void read_message(std::string&& message) {
    std::cout << "r-value: " << message << std::endl;
    // note: message itself is a lvalue, because it has a name!
}

TEST_CASE( "Rvalue References" ) {
    std::string s1 = "hello ";
    std::string s2 = "world";

    read_message(s1);  // lvalue overload
    read_message(s1 + s2);  // rvalue overload (temporary object)
    read_message("test");   // rvalue overload (a literal cannot be lvalue)
    read_message(std::move(s1));   // rvalue overload (std::move converts lvalue to rvalue)
}
