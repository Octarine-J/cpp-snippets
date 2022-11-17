#include "quick_find.hpp"
using namespace union_find;

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Union Find - Quick Find - UF_QuickFind" ) {
    UF_QuickFind u {0, 1, 1, 8, 8, 0, 0, 1, 8, 8};

    REQUIRE( u.connected(0, 5) );
    REQUIRE( u.connected(0, 6) );
    REQUIRE( u.connected(2, 7) );
    REQUIRE( u.connected(8, 9) );
    REQUIRE( not u.connected(0, 8) );
    REQUIRE( not u.connected(0, 1) );

    u.unite(6, 1);
    REQUIRE( u.connected(1, 6) );
    REQUIRE( u.connected(0, 5) );
    REQUIRE( not u.connected(1, 3) );
}

TEST_CASE( "Union Find - Quick Find - UF_QuickFind Init" ) {
    UF_QuickFind u = quick_find(10, {});
    REQUIRE( u[6] == 6 );
}

TEST_CASE( "Union Find - Quick Find" ) {
    std::vector<std::pair<int, int>> pairs = {
            {4, 3}, {3, 8}, {6, 5}, {9, 4},
            {2, 1}, {8, 9}, {5, 0}, {7, 2},
            {6, 1}
    };

    UF_QuickFind u = quick_find(10, pairs);

    REQUIRE( u.connected(0, 7) );
    REQUIRE( u.connected(5, 2) );
    REQUIRE( u.connected(3, 9) );
    REQUIRE( u.connected(8, 9) );
    REQUIRE( not u.connected(0, 8) );
    REQUIRE( not u.connected(6, 4) );
}
