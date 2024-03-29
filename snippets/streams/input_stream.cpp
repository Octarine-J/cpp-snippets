#include <iostream>
#include <sstream>

#include <catch2/catch_test_macros.hpp>

// example how to properly read from std::cin with error handling
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
            is.clear();  // reset error state

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

TEST_CASE( "Input Stream" ) {
    std::string input = "12 7 90\n";
    std::istringstream is {input};

    // can use with std::cin
    int result = read_and_sum_numbers(is);

    REQUIRE( result == 109 );
}

TEST_CASE( "Input Stream With Bad Tokens" ) {
    std::string input = "12 xx 90 aa\n";
    std::istringstream is {input};

    int result = read_and_sum_numbers(is);
    REQUIRE( result == 102 );
}

TEST_CASE( "Read From Input Stream Line by Line" ) {
    std::istringstream is {"4 12 7\nEric Schmidt\n"};

    std::string line;
    std::getline(is, line);
    REQUIRE( line == "4 12 7" );

    std::getline(is, line);
    REQUIRE( line == "Eric Schmidt" );
}

TEST_CASE( "Optimize Reading Speed for Large Input" ) {
    // useful for reading big data
    // TODO: this causes test failures when run from CLion
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);

    std::istringstream is {"1 2 3\n"};
    int a, b;
    is >> a >> b;

    REQUIRE( a == 1 );
    REQUIRE( b == 2 );
}
