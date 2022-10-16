#include <numeric>
#include "linked_list.hpp"

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Add First and Add Last in Linked List" ) {
    ds::LinkedList<int> list;
    REQUIRE( 0 == list.size() );

    list.add_last(1);
    REQUIRE( 1 == list.size() );
    REQUIRE( 1 == list[0] );
    REQUIRE( 1 == list.top() );

    list.add_last(2);
    REQUIRE( 2 == list.size() );
    REQUIRE( 1 == list[0] );
    REQUIRE( 2 == list[1] );

    list.add_first(-1);
    REQUIRE( 3 == list.size() );
    REQUIRE( -1 == list[0] );
    REQUIRE( 1 == list[1] );
    REQUIRE( 2 == list[2] );

    list.add_first(-2);
    REQUIRE( 4 == list.size() );
    REQUIRE( -2 == list[0] );
    REQUIRE( -1 == list[1] );
    REQUIRE( 1 == list[2] );
    REQUIRE( 2 == list[3] );

    list.add_last(3);
    REQUIRE( 5 == list.size() );
    REQUIRE( -2 == list[0] );
    REQUIRE( -1 == list[1] );
    REQUIRE( 1 == list[2] );
    REQUIRE( 2 == list[3] );
    REQUIRE( 3 == list[4] );
}

TEST_CASE ( "Remove Element in Linked List" ) {
    ds::LinkedList<int> list;
    REQUIRE_THROWS_AS( list.remove_first(), std::invalid_argument );

    list.add_last(1);
    list.add_first(2);
    list.remove_first();

    REQUIRE( 1 == list.size() );
    REQUIRE( 1 == list.top() );
}

TEST_CASE( "Empty Linked List" ) {
    ds::LinkedList<int> list;
    REQUIRE( 0 == list.size());
    REQUIRE_THROWS_AS( list[0], std::invalid_argument );
    REQUIRE_THROWS_AS( list.top(), std::invalid_argument );
}

TEST_CASE( "ForEach Element in Linked List" ) {
    ds::LinkedList<int> list = {3, 1, 2};

    int sum = std::accumulate(list.begin(), list.end(), 0);
    REQUIRE( 6 == sum );
}

TEST_CASE( "ForEach Element in Empty Linked List" ) {
    ds::LinkedList<int> list;

    int sum = std::accumulate(list.begin(), list.end(), 0);
    REQUIRE( 0 == sum );
}

TEST_CASE( "Reverse Linked List" ) {
    ds::LinkedList<int> list = {1, 2, 3, 4, 5};

    list.reverse();

    REQUIRE( 5 == list[0] );
    REQUIRE( 4 == list[1] );
    REQUIRE( 3 == list[2] );
    REQUIRE( 2 == list[3] );
    REQUIRE( 1 == list[4] );

    list.add_first(6);
    list.add_last(7);

    REQUIRE( 6 == list[0] );
    REQUIRE( 7 == list[6] );
}

TEST_CASE( "Reverse Empty Linked List" ) {
    ds::LinkedList<int> list;

    list.reverse();
    REQUIRE( 0 == list.size() );

    list.add_first(1);
    list.add_last(2);

    REQUIRE( 1 == list.top() );
    REQUIRE( 2 == list[1] );
}
