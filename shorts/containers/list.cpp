#include <list>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

/**
 * list is a doubly-linked list
 * forward_list is a singly-linked list
 */
TEST_CASE( "Add to List" ) {
    std::list<std::string> names = {"Vasya", "Oleg", "Nastya"};

    names.insert(names.begin(), "Sveta");

    REQUIRE( names.front() == "Sveta" );
    REQUIRE( names.size() == 4 );

    // insert the entire second list without destroying it
    std::list<std::string> more_names = {"Vadim", "Olya"};
    names.insert(names.cend(), more_names.cbegin(), more_names.cend());

    REQUIRE( names.back() == "Olya" );
    REQUIRE( names.size() == 6 );
}

TEST_CASE( "Remove from List" ) {
    std::list<std::string> names = {"Vasya", "Oleg", "Nastya"};

    names.erase(names.begin());

    REQUIRE( names.front() == "Oleg" );
    REQUIRE( names.size() == 2 );
}

// Add the entire list to another list in O(1); destroys the second list
TEST_CASE( "Combine Two Lists (Splice)" ) {
    std::list<std::string> languages = {"C++", "Go", "Rust"};
    std::list<std::string> fp_languages = {"Haskell", "Erlang"};

    // insert the second list at pos 1 in the first list
    languages.splice(++languages.cbegin(), fp_languages);

    REQUIRE( languages.size() == 5 );
    REQUIRE( *(++languages.cbegin()) == "Haskell" );
    REQUIRE( languages.back() == "Rust" );
}

// Merge two SORTED lists
TEST_CASE( "Merge Two Sorted Lists" ) {
    std::list<int> x = {1, 3, 5};
    std::list<int> y = {2, 4, 6};

    x.merge(y);  // destroys y

    REQUIRE( x.size() == 6 );
    REQUIRE( x.front() == 1 );
    REQUIRE( x.back() == 6 );
}

TEST_CASE( "Reverse a List" ) {
    std::list<int> x = {1, 2, 3};

    x.reverse();

    REQUIRE( x.front() == 3 );
    REQUIRE( x.back() == 1);
}

TEST_CASE( "Remove Duplicates from a Sorted List" ) {
    std::list<int> x = {5, 2, 2, 3, 1, 3};

    x.sort();

    REQUIRE( x == std::list<int>({1, 2, 2, 3, 3, 5}) );

    x.unique();  // erase duplicates, the list must be sorted

    REQUIRE( x == std::list<int>({1, 2, 3, 5}) );
}
