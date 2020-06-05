#include <algorithm>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"


TEST_CASE( "Search in a Container with Lambda" ) {
    std::vector<std::string> words = {"archive", "business", "book"};

    // find words starting with b;
    auto result = std::find_if(words.begin(), words.end(), [](auto& word) {
        return word[0] == 'b';
    });

    REQUIRE( *result == "business" );  // first result

    ++result;
    REQUIRE( *result == "book" );  // second result
}

TEST_CASE( "Search in a Container using an STD Functor" ) {
    std::vector<int> v = {7, 12, 5, 8};

    auto result = std::find_if(v.begin(), v.end(), 
        std::bind(std::greater_equal<>(), std::placeholders::_1, 10));

    REQUIRE( *result == 12 );
}

TEST_CASE( "Search in a Container using a Member Function" ) {
    std::vector<std::string> words = {"archive", "business", "book"};

    // find an empty string
    // need to use std::mem_fn to pass a member function
    auto result = std::find_if(words.begin(), words.end(), std::mem_fn(&std::string::empty));

    REQUIRE( result == words.cend() );  // no empty strings
}

TEST_CASE( "Count Items that Match Criteria" ) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    size_t result = std::count_if(v.begin(), v.end(), [](auto value) {
        return value % 2 == 0;
    });

    REQUIRE( result == 4 );
}
