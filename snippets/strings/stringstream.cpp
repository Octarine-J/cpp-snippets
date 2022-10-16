#include <iomanip>
#include <sstream>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Formatting With String Stream" ) {
    std::string name = "John";
    double salary = 5000.927;

    // can't add a string to a double:
    // std::string result = name + ": " + salary;

    // so we use a string stream
    std::stringstream ss;

    // fixed: use non-scientific notation for numbers (5000, not 5e+3)
    // setprecision: number of digits after the point
    ss << name << ": " << std::fixed << std::setprecision(2) << salary;
    std::string result = ss.str();

    REQUIRE( result == "John: 5000.93" );
}
