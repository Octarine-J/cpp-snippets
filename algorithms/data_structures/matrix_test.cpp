#include "matrix.hpp"

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"


TEST_CASE( "Zero Dimension Matrix" ) {
    REQUIRE_THROWS_AS( ds::matrix<int>(0, 0), std::invalid_argument );
    REQUIRE_THROWS_AS( ds::matrix<int>(1, 0), std::invalid_argument );
    REQUIRE_THROWS_AS( ds::matrix<int>(0, 1), std::invalid_argument );
}

TEST_CASE( "1x1 Matrix" ) {
    ds::matrix<int> a(1, 1);
    a(0, 0) = 7;
    
    REQUIRE( a(0, 0) == 7 );

    ds::matrix<int> b(1, 1, 100);
    REQUIRE( b(0, 0) == 100 );
}

TEST_CASE( "1x2 Matrix" ) {
    ds::matrix<int> a(1, 2);
    a(0, 0) = 3;
    a(0, 1) = 4;
    
    REQUIRE( a(0, 0) == 3 );
    REQUIRE( a(0, 1) == 4 );

    ds::matrix<int> b(1, 2, 100);
    REQUIRE( b(0, 0) == 100 );
    REQUIRE( b(0, 1) == 100 );
}

TEST_CASE( "2x1 Matrix" ) {
    ds::matrix<int> a(2, 1);
    a(0, 0) = 3;
    a(1, 0) = 4;
    
    REQUIRE( a(0, 0) == 3 );
    REQUIRE( a(1, 0) == 4 );

    ds::matrix<int> b(2, 1, 100);
    REQUIRE( b(0, 0) == 100 );
    REQUIRE( b(1, 0) == 100 );
}

TEST_CASE( "2x2 Matrix" ) {
    ds::matrix<int> a(2, 2);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(1, 0) = 3;
    a(1, 1) = 4;
    
    REQUIRE( a(0, 0) == 1 );
    REQUIRE( a(0, 1) == 2 );
    REQUIRE( a(1, 0) == 3 );
    REQUIRE( a(1, 1) == 4 );

    ds::matrix<int> b(2, 2, 100);
    REQUIRE( b(0, 0) == 100 );
    REQUIRE( b(0, 1) == 100 );
    REQUIRE( b(1, 0) == 100 );
    REQUIRE( b(1, 1) == 100 );
}

