#include <string>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Use Iterator to Modify a Container" ) {
    std::string s = "a sample";

    for (auto it = s.begin(); it != s.end(); ++it) {
        (*it) = static_cast<char>(toupper(*it));
    }

    REQUIRE( s == "A SAMPLE");
}

TEST_CASE( "Const Iterator" ) {
    std::string s = "a sample";

    for (auto it = s.cbegin(); it != s.cend(); ++it) {
        REQUIRE( *it < 'z' );
    }
}

TEST_CASE( "Iterator Arithmetic" ) {
    std::string s = "a sample";

    // get the middle element
    auto mid = s.begin() + (s.end() - s.begin()) / 2;

    REQUIRE( *mid == 'm' );
}
