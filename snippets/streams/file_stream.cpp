#include <iostream>
#include <fstream>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Read File" ) {
    std::fstream f {"CMakeCache.txt"};

    REQUIRE( f );  // false if file can't be opened

    std::string s;
    std::getline(f, s);

    REQUIRE( s == "# This is the CMakeCache file." );
}
