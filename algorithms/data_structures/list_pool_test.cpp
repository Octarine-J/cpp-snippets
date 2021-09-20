#include "list_pool.hpp"

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

TEST_CASE( "Create" ) {
    ds::ListPool<char> pool;

    auto pos_a = pool.allocate('a', 0);
    REQUIRE( 1 == pos_a );

    auto pos_b = pool.allocate('b', pos_a);
    REQUIRE( 2 == pos_b );

    auto tail_a = pool.free(pos_a);
    REQUIRE( 0 == tail_a );

    auto pos_c = pool.allocate('c', pos_b);
    REQUIRE( 1 == pos_c );
    REQUIRE( 'c' == pool.value(pos_c) );
    REQUIRE( pos_b == pool.next(pos_c) );
}

TEST_CASE( "FreeList" ) {
    ds::ListPool<char> pool;
    auto pos_a = pool.allocate('a', 0);
    auto pos_b = pool.allocate('b', pos_a);
    auto pos_c = pool.allocate('c', pos_b);

    ds::free_list(pool, pos_c);

    auto pos_d = pool.allocate('d', 0);

    REQUIRE( pos_a == pos_d );
}
