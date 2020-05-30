#include <bitset>
#include <sstream>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

TEST_CASE( "Set and Test Flags" ) {
    std::bitset<8> flags;

    // set values
    flags.set(3);  // zero-indexed
    flags[6] = true;

    // check if a value is set
    REQUIRE( flags.test(3) );

    // output
    std::stringstream ss;
    ss << flags;

    // the order is reversed (from right to left)
    REQUIRE( ss.str() == "01001000" );
}

TEST_CASE( "BitSet operators" ) {
    // bitset supports all bit operators:
    // &, |, ^, ~, <<, >>, &=, |=, ^=, <<=, >>=

    std::bitset<4> s1("0111");
    std::bitset<4> s2("1010");

    auto s3 = s1 & s2;

    std::stringstream output1;
    output1 << s3;

    REQUIRE( output1.str() == "0010" );

    s1 <<= 2;

    std::stringstream output2;
    output2 << s1;

    REQUIRE( output2.str() == "1100" );
}
