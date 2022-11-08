#include <string>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "String Init" ) {
    std::string s1;  // empty string
    REQUIRE( s1.empty() );

    std::string s2(10, 'c');
    REQUIRE( s2 == "cccccccccc" );
    REQUIRE( s2.size() == 10 );
    REQUIRE( s2[0] == 'c' );

    std::string s3 {"hello, " + s2};  // direct initialization
    REQUIRE( s3 == "hello, cccccccccc" );
}

TEST_CASE( "String Modification" ) {
    std::string s = "hello";

    // change the string character by character
    for (auto& c : s) {  // c is a reference to a character in s3
        c = static_cast<char>(toupper(c));
    }

    REQUIRE( s == "HELLO" );
}

TEST_CASE( "Substring" ) {
    std::string s = "hello, world";

    // substr(pos, len)
    REQUIRE( s.substr(0, 1) == "h" );
    REQUIRE( s.substr(0, 5) == "hello" );
    REQUIRE( s.substr(1, 2) == "el" );
    REQUIRE( s == "hello, world" );
}

TEST_CASE( "String Replacement" ) {
    std::string s = "hello, world";

    // replace modifies the string
    // replace: at which pos, how many characters, for what
    REQUIRE( s.replace(7, 5, "universe") == "hello, universe" );
    REQUIRE( s == "hello, universe" );
}

TEST_CASE( "String Replacement with Search" ) {
    std::string source = "hello, world";
    std::string target = "world";

    source.replace(source.find(target), target.size(), "universe");

    REQUIRE( source == "hello, universe" );
}
