#include <cctype>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Char Category" ) {
    char c = 'a';
    
    // is letter or digit
    REQUIRE( std::isalnum(c) );
    // is letter
    REQUIRE( std::isalpha(c) );

    // is digit
    REQUIRE( not std::isdigit(c) );
    // is hexadecimal digit
    REQUIRE( std::isxdigit(c) );

    // is lowercase letter
    REQUIRE( std::islower(c) );
    // is uppercase letter
    REQUIRE( not std::isupper(c) );

    // is control character
    REQUIRE( not std::iscntrl(c) );
    // is printable and not space
    REQUIRE( std::isgraph(c) );
    // is printable
    REQUIRE( std::isprint(c) );
    // is punctuation character
    REQUIRE( not std::ispunct(c) );
    // is whitespace (tab, newline, space, ...)
    REQUIRE( not std::isspace(c) );
}

TEST_CASE( "Char Case Functions" ) {
    // to lower case
    REQUIRE( std::tolower('C') == 'c' );

    // to upper case
    REQUIRE( std::toupper('c') == 'C' );
}
