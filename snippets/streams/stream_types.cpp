#include <iostream>

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
