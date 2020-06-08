#include <string>
#include <sstream>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

// Streams can be navigated using seekg (seek get, for input steams)
// and seekp (seek put, for output streams).
TEST_CASE( "Navigating Stream with Seek" ) {
    std::string s("43 12 7 92 16 5");
    std::istringstream ss(s);

    int number;

    ss >> number;
    REQUIRE( number == 43 );

    // seek to start again
    ss.seekg(std::ios_base::beg);
    ss >> number;
    REQUIRE( number == 43 );

    // seek 3 bytes from the current position
    ss.seekg(3, std::ios_base::cur);
    ss >> number;
    REQUIRE( number == 7 );

    // seek 4 bytes from the end
    ss.seekg(-4, std::ios_base::end);
    ss >> number;
    REQUIRE( number == 16 );

    // get the current position
    REQUIRE( ss.tellg() == 13 );
}

// When working with binary files, a stream should be opened in
// (ios_base::out | std::ios_base::binary) mode
// to prevent implicit byte conversions (such as line endings).

// Another useful modes are:
// std::ios_base::app    - append to a file
// std::ios_base::trunc  - truncate the file (erase all contents)
// std::ios_base::in     - open for input (default for input streams)
// std::ios_base::out    - open for output (default for output streams)
