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

TEST_CASE( "Matrix - Set Row" ) {
    const size_t max_rows = 3;
    const size_t max_cols = 3;
    const int init_value = 100;
    const int updated_value = 200;

    // test all sizes from 1x1 to 3x3
    for (size_t num_rows = 1; num_rows <= max_rows; ++num_rows) {
        for (size_t num_cols = 1; num_cols <= max_cols; ++num_cols) {
            for (size_t row_to_set = 0; row_to_set < num_rows; ++row_to_set) {
                ds::matrix<int> a(num_rows, num_cols, init_value);
                a.set_row(row_to_set, updated_value);

                for (size_t i = 0; i < num_rows; ++i) {
                    for (size_t j = 0; j < num_cols; ++j) {
                        if (i == row_to_set) {
                            REQUIRE( a(i, j) == updated_value );
                        } else {
                            REQUIRE( a(i, j) == init_value );
                        }
                    }
                }
            }
        }
    }
}
