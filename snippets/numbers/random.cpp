#include <random>
#include <iostream>
#include <string>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Uniform Distribution" ) {
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> dist(1, 6);

    for (int i = 0; i < 100; ++i) {
        int dice = dist(engine);
        REQUIRE( (dice >= 1 && dice <= 6) );
    }
}

TEST_CASE( "Random String" ) {
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> dist('a', 'z');

    std::string s(16, '*');  // init string with len = 16 and placeholder chars
    for (char& c : s) {
        int r = dist(engine);
        c = static_cast<char>(r);
    }

    for (const char c : s) {
        REQUIRE( (c >= 'a' && c <= 'z' ) );
    }
}
