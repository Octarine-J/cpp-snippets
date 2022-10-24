#include <string>
#include <strstream>

#include <catch2/catch_test_macros.hpp>


// Bidirectional streams allow both reading and writing operations.
// They are the most useful with files (fstream), when a file does not fit into memory.
TEST_CASE( "Read and Write to a Bidirectional Stream" ) {
    std::string s("1 09-9999-9999 2 03-7777-7777 3 03-2222-2222");
    std::stringstream ss(s);

    const int target_id = 2;

    while (ss) {
        int id;
        std::string number;

        ss >> id;

        if (id == target_id) {
            // IMPORTANT: seek the writing position to the current read position
            ss.seekp(ss.tellg());
            // overwrite the data
            ss << " " << "05-5555-5555";
            break;
        }

        ss >> number;
    }

    REQUIRE( ss.str() == "1 09-9999-9999 2 05-5555-5555 3 03-2222-2222" );
}

// Two streams can be tied with stream.tie(&otherStream) method.
// When input or output occurs to the first stream, the other stream
// is automatically flushed.
// By default, cin/cout and cerr/cout are tied.
