#include <catch2/catch_test_macros.hpp>


// pair has easier field access than tuple
TEST_CASE( "Create Pair" ) {
    auto p = std::make_pair(1, std::string("one"));

    REQUIRE( p.first == 1 );
    REQUIRE( p.second == "one" );
}
