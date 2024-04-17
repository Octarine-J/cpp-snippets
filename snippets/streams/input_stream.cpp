#include <iostream>
#include <sstream>

#include <catch2/catch_test_macros.hpp>

// example how to properly read from std::cin with error handling
// a stream can be in 4 states:
// - good
// - eof
// - fail  (read unexpected input)
// - bad   (e.g. a disk error)
int read_and_sum_numbers(std::istream& is) {
    std::cout << "Input numbers to add (CTRL+Z on Windows / CTRL+D on UNIX to stop.)\n";

    if (!is.good()) {  // = not bad && not eof
        std::cerr << "Error: cin is in a bad state.\n";
        return 0;
    }

    int sum = 0;
    int number;

    while (!is.bad()) {  // note that eof is not bad
        is >> number;

        if (is.eof()) {
            break;
        }

        if (is.fail()) {  // last operation failed
            is.clear();   // reset error state

            std::string bad_token;
            is >> bad_token;
            std::cerr << "Warning: bad token '" << bad_token << "'\n";

            continue;
        }

        sum += number;
    }

    std::cout << "sum = " << sum << std::endl;
    return sum;
}

TEST_CASE( "Input Stream: Read" ) {
    std::string input = "12 7 90\n";
    std::istringstream is {input};

    // can use with std::cin
    int result = read_and_sum_numbers(is);

    REQUIRE( result == 109 );
}

TEST_CASE( "Input Stream: Read With Bad Tokens" ) {
    std::string input = "12 xx 90 aa\n";
    std::istringstream is {input};

    int result = read_and_sum_numbers(is);
    REQUIRE( result == 102 );
}

TEST_CASE( "Input Stream: Auto-Throw Exceptions on Bad Input" ) {
    std::istringstream is {"7.14 3.71x 1.67"};

    // throw exceptions when state is either 'bad' or 'fail'
    is.exceptions(is.exceptions() | std::ios::badbit | std::ios::failbit );

    double x, y, z;
    REQUIRE_THROWS_AS( is >> x >> y >> z, std::ios::failure );
}

TEST_CASE( "Input Stream: Clear Bad Input State" ) {
    std::istringstream is {"1.234usd"};

    double a, b;
    is >> a >> b;

    char c;
    // can't read c now: the stream is in a bad state
    // after an attempt to read 'double b'
    is.clear();
    is >> c;

    REQUIRE( a == 1.234 );
    REQUIRE( c == 'u' );
}

TEST_CASE( "Input Stream: Set Bad Input State" ) {
    std::istringstream is {"42 77"};
    is.clear(std::ios::failbit);

    int x = -1;
    is >> x;  // can't read 42: stream is in a fail state

    REQUIRE( x != 42 );
}

TEST_CASE( "Input Stream: Read Line by Line" ) {
    std::istringstream is {"4 12 7\nEric Schmidt\n"};

    std::string line;
    std::getline(is, line);
    REQUIRE( line == "4 12 7" );

    std::getline(is, line);
    REQUIRE( line == "Eric Schmidt" );
}

// == Additional info ==
// Optimize input stream to fast reading of a large dataset
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
