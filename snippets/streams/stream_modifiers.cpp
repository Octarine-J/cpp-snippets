#include <iomanip>
#include <iostream>
#include <sstream>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Print Boolean" ) {
    std::stringstream ss;

    // print boolean (as "true" or "false")
    bool b = true;
    ss << std::boolalpha << b;

    REQUIRE( ss.str() == "true" );
}

TEST_CASE( "Print Hex Number") {
    std::stringstream ss;

    int h = 255;
    ss << std::hex << std::showbase << h;

    REQUIRE( ss.str() == "0xff" );

    ss.str("");
    ss << std::dec << h;  // undo hex

    REQUIRE( ss.str() == "255" );
}

TEST_CASE( "Print Formatted Number" ) {
    std::stringstream ss;

    // print a formatted number (000123)
    ss << std::setfill('0') << std::setw(6) << 123;
    REQUIRE( ss.str() == "000123" );

    ss.str("");
    ss << std::setfill(' ');  // undo fill

    // print a floating point number
    // NOTE: without std::fixed, it would be total 5 digits (before and after the dot)
    double a = 27.9876125;
    ss << std::fixed << std::setprecision(5) << a;
    REQUIRE( ss.str() == "27.98761" );
}

TEST_CASE( "Print Money" ) {
    std::stringstream ss;

    // set current locale (for monetary and date/time output)
    ss.imbue(std::locale("ja_JP.UTF8"));

    // print monetary amount
    ss << std::put_money("12000");

    REQUIRE( ss.str() == "12,000" );
}

TEST_CASE( "Print Date/Time" ) {
    std::stringstream ss;

    // print date/time
    time_t ts = std::time(nullptr);
    tm* localTs = std::localtime(&ts);

    std::cout << std::put_time(localTs, "%c") << std::endl;
}
