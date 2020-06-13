#include <iostream>
#include <regex>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"


TEST_CASE( "Search in a substring" ) {
    std::string input = "Code is ZZ 12345-9999.";

    std::regex re(R"(\w{2}\s*\d{5}(-\d{4})?)");
    std::smatch matches;

    bool found_match = std::regex_search(input, matches, re);
    
    REQUIRE( found_match );
    REQUIRE( matches[0] == "ZZ 12345-9999" );
}

TEST_CASE( "Regex without creating a group" ) {
    std::regex re("ab(?:c|d)");

    REQUIRE( std::regex_match("abc", re) );
    REQUIRE( std::regex_match("abd", re) );
    REQUIRE( ! std::regex_match("abe", re) );
}

TEST_CASE( "Match digits" ) {
    // digits
    std::regex re(R"(\d+)");

    REQUIRE( std::regex_match("123", re) );
    REQUIRE( std::regex_match("7", re) );
    REQUIRE( ! std::regex_match("a", re) );
    REQUIRE( ! std::regex_match("", re) );

    // not digits
    re = std::regex(R"(\D+)");
    
    REQUIRE( std::regex_match("abc", re) );
    REQUIRE( std::regex_match(" ", re) );
    REQUIRE( ! std::regex_match("123", re) );
}

TEST_CASE( "Match alphanumeric characters" ) {
    // alnum
    std::regex re(R"(\w+)");

    REQUIRE( std::regex_match("123", re) );
    REQUIRE( std::regex_match("abc7", re) );
    REQUIRE( ! std::regex_match("abc abc", re) );

    // not alnum
    re = std::regex(R"(\W+)");
    REQUIRE( std::regex_match(" \t '", re) );
    REQUIRE( ! std::regex_match("abc7", re) );
}

TEST_CASE( "Match space" ) {
    // space
    std::regex re(R"(\s+)");

    REQUIRE( std::regex_match(" ", re) );
    REQUIRE( std::regex_match("\t", re) );
    REQUIRE( std::regex_match("\t\n\n", re) );

    // not space
    re = std::regex(R"(\S+)");
    REQUIRE( std::regex_match("av's", re) );
    REQUIRE( ! std::regex_match("ab cd", re) );
}

TEST_CASE( "Back references" ) {
    // 4 digits followed by a dash, then the same 4 digits
    std::regex re(R"(\d{4}-\1)");

    REQUIRE( std::regex_match("1234-1234", re) );
    REQUIRE( std::regex_match("9822-9822", re) );
    REQUIRE( ! std::regex_match("9822-9823", re) );
}

TEST_CASE( "Match groups" ) {
    std::regex re(R"((\d{3})-(\d{4}))");

    std::cmatch match;
    bool found = std::regex_match("127-0001", match, re);

    REQUIRE( found );
    REQUIRE( match[0] == "127-0001");
    REQUIRE( match[1] == "127");
    REQUIRE( match[2] == "0001");
}
