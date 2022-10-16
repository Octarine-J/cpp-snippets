#include <cstring>
#include <string>
using namespace std::string_literals;

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "C-Style Strings" ) {
    // string literals are zero-terminated C-style char arrays
    // stored in read-only memory, should not be modified
    const char* s = "steam engine";

    REQUIRE( *(s + strlen(s)) == '\0' );

    // to be able to modify a C-style string, use array syntax
    // this will copy the string from the string pool into a new array
    char t[] = "text";
    t[2] = 's';

    // use -s suffix to make a proper std::string literal
    REQUIRE( t == "test"s );
}
