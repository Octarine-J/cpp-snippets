#include <sstream>

#include <catch2/catch_test_macros.hpp>

// low-level stream operations

TEST_CASE( "Raw Writing to Stream" ) {
    std::stringstream ss;

    // raw output to the stream
    ss.write("raw output", 10);  // a number of characters
    ss.put('\n');  // a single char

    REQUIRE( ss.str() == "raw output\n" );
}
