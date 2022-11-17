#include "quick_union.hpp"
using namespace union_find;

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Union Find - Quick Union - UF_QuickUnion" ) {
    UF_QuickUnion u {0, 1, 9, 4, 9, 6, 6, 7, 8, 9};

    REQUIRE( u.connected(0, 0) );
    REQUIRE( u.connected(2, 9) );
    REQUIRE( u.connected(3, 9) );
    REQUIRE( u.connected(5, 6) );
    REQUIRE( not u.connected(1, 9) );
    REQUIRE( not u.connected(3, 6) );

    u.unite(3, 5);
    REQUIRE( u.connected(3, 5) );
    REQUIRE( u.connected(2, 6) );
    REQUIRE( u.connected(4, 5) );
    REQUIRE( not u.connected(5, 1) );
}

TEST_CASE( "Union Find - Quick Union - UF_QuickUnion Init" ) {
    UF_QuickUnion u = quick_union(10, {});
    REQUIRE( u[6] == 6 );
}

TEST_CASE( "Union Find - Quick Union" ) {
    std::vector<std::pair<int, int>> pairs = {
            {4, 3}, {3, 8}, {6, 5}, {9, 4},
            {2, 1}, {8, 9}, {5, 0}, {7, 2},
            {6, 1}
    };

    UF_QuickUnion u = quick_union(10, pairs);

    REQUIRE( u.connected(0, 7) );
    REQUIRE( u.connected(5, 2) );
    REQUIRE( u.connected(3, 9) );
    REQUIRE( u.connected(8, 9) );
    REQUIRE( not u.connected(0, 8) );
    REQUIRE( not u.connected(6, 4) );
}

