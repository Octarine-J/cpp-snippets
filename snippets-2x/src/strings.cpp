#include <iostream>
#include <print>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Modern Print" ) {
    // since C++23
    std::println("hello, 世界");  // any C++23 compiler should support sources in UTF-8

    // can specify to which stream to print
    int error_code = 42;
    std::println(std::cerr, "Error {}", error_code);
}

TEST_CASE( "Modern String Format" ) {
    // since C++20
    int x = 2, y = 3;
    std::string s = std::format("{} + {} = {}", x, y, x + y);
    REQUIRE( s == "2 + 3 = 5" );

    int z = 42;
    // use # to output prefix (such as 0x)
    // use capital X for upper-case hex digits
    // use 0: to reuse the same input argument
    s = std::format("hex: {0:#X}, oct: {0:o}, bin: {0:b}", z);
    REQUIRE( s == "hex: 0X2A, oct: 52, bin: 101010" );

    // use ^ to center text
    // can specify field width (here: 12)
    // can specify fill character (here: =)
    s = std::format("{:=^12b}", z);
    REQUIRE( s == "===101010===" );
}

TEST_CASE( "New String Methods" ) {
    std::string path = "/usr/bin/python";

    // C++20
    REQUIRE( path.starts_with("/usr") );
    REQUIRE( path.ends_with("/python") );

    // C++23
    REQUIRE( path.contains("/bin/") );
}
