#include <iostream>
#include <sstream>
#include <stdexcept>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Stream Types" ) {
    // cout = [c]haracter [out]put
    // buffered
    std::cout << "hello, world";
    std::cout << std::endl; // flushes the buffer!

    // non-buffered error msg stream
    std::cerr << "error message\n";

    // buffered error msg stream
    std::clog << "(buffered) error message" << std::endl;
}

TEST_CASE( "Force Stream to Use Exceptions" ) {
    std::istringstream ss {""};

    // force stream to use exceptions
    // can set also on other streams such as std::cin or std::cout
    ss.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);

    int x;
    REQUIRE_THROWS_AS( ss >> x, std::ios_base::failure );

    ss.clear();  // clear error state of the stream
}
