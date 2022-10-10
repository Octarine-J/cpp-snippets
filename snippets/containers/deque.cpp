#include <deque>

#include <catch2/catch_test_macros.hpp>


// Deque DOES NOT invalidate iterators on insert to front/back

TEST_CASE( "Add and Remove from Deque" ) {
    std::deque<int> q {1, 2, 3};

    q.push_front(4);  // O(1), same as push_back
    q.pop_back();

    REQUIRE( q.front() == 4 );
    REQUIRE( q.back() == 2 );
}
