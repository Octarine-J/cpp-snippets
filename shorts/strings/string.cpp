#include <iostream>
#include <string>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"


TEST_CASE( "String Init" ) {
    std::string s1;  // empty string

    REQUIRE( s1.empty() );
    
    std::string s2(10, 'c');
    
    REQUIRE( s2 == "cccccccccc" );
    REQUIRE( s2.size() == 10 );
    REQUIRE( s2[0] == 'c' );

    std::string s3("hello, " + s2);  // direct initialization

    REQUIRE( s3 == "hello, cccccccccc" );
}

TEST_CASE( "String Modification" ) {
    std::string s = "hello";

    // change the string character by character
    for (auto& c : s) {  // c is a reference to a character in s3
        c = toupper(c);
    }

    REQUIRE( s == "HELLO" );
}

TEST_CASE( "Substring" ) {
    std::string s = "hello, world";

    REQUIRE( s.substr(0, 1) == "h" );
    REQUIRE( s.substr(0, 5) == "hello" );
    REQUIRE( s == "hello, world" );
}

TEST_CASE( "String Replacement" ) {
    std::string s = "hello, world";

    // replace modifies the string
    REQUIRE( s.replace(7, 12, "universe") == "hello, universe" );
    REQUIRE( s == "hello, universe" );
}

TEST_CASE( "String Replacement with Search" ) {
    std::string s = "hello, world";

    s.replace(s.find("world"), s.size(), "universe");

    REQUIRE( s == "hello, universe" );
}
