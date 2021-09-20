#include <algorithm>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"


TEST_CASE( "Binary Search" ) {
    std::vector<int> v = {11, 32, 33, 50, 67};

    // returns an iterator pointing to an element >= x (vector must be sorted)
    auto it = std::lower_bound(v.begin(), v.end(), 40);

    REQUIRE( *it == 50 );

    // can use this iterator to insert a value so the vector remains sorted
    v.insert(it, 40);

    REQUIRE( std::is_sorted(v.begin(), v.end()) );

    // "binary_search" returns true or false:
    REQUIRE( std::binary_search(v.begin(), v.end(), 40) );
}

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

TEST_CASE( "Find Any Value from a Set of Values" ) {
    std::vector<int> v = {1, 3, 5, 15, 7, 24, 99, 42, 13, 11};
    std::vector<int> targets = {13, 3};

    auto it = std::find_first_of(v.begin(), v.end(), targets.begin(), targets.end());

    REQUIRE( *it == 3 );
}

// count

TEST_CASE( "Count Items by Equality" ) {
    std::vector<std::string> positions = 
        {"student", "employee", "student", "manager", "student"};

    size_t num_students = std::count(positions.begin(), positions.end(), "student");

    REQUIRE( num_students == 3 );
}

TEST_CASE( "Count Items by Criteria" ) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    size_t num_even = std::count_if(v.begin(), v.end(), [](auto value) {
        return value % 2 == 0;
    });

    REQUIRE( num_even == 4 );
}
