#include "knapsack.hpp"

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

using namespace alg::opt::knapsack;

TEST_CASE( "Knapsack - No Items" ) {
    std::vector<item> items = {};
    solution sol = optimal_fit(items, 0);

    REQUIRE( sol.max_value == 0 );
    REQUIRE( sol.pos.empty() );
}

TEST_CASE( "Knapsack - 3 Items" ) {
    std::vector<item> items = {
        {3000, 4},
        {2000, 3},
        {1500, 1}
    };
    solution sol = optimal_fit(items, 4);

    REQUIRE( sol.max_value == 3500 );
    REQUIRE( sol.pos == std::vector<size_t>{1, 2} );
}

TEST_CASE( "Knapsack - 4 Items" ) {
    std::vector<item> items = {
        {3000, 4},
        {2000, 3},
        {1500, 1},
        {2000, 1},
    };
    solution sol = optimal_fit(items, 4);

    REQUIRE( sol.max_value == 4000 );
    REQUIRE( sol.pos == std::vector<size_t>{1, 3} );
}

TEST_CASE( "Knapsack - Duplicate Items" ) {
    std::vector<item> items = {
        {1000, 2},
        {1000, 2},
        {1000, 2},
        {10000, 5},
        {10000, 5},
        {13000, 8},
        {7000, 3},
    };
    solution sol = optimal_fit(items, 10);

    REQUIRE( sol.max_value == 20000 );
    REQUIRE( sol.pos == std::vector<size_t>{3, 4} );
}

TEST_CASE( "Knapsack - One Item That Does Not Fit" ) {
    std::vector<item> items = {
        {3000, 5}
    };
    solution sol = optimal_fit(items, 4);

    REQUIRE( sol.max_value == 0 );
    REQUIRE( sol.pos == std::vector<size_t>{} );
}

TEST_CASE( "Knapsack - One Item That Fits" ) {
    std::vector<item> items = {
        {3000, 5}
    };
    solution sol = optimal_fit(items, 5);

    REQUIRE( sol.max_value == 3000 );
    REQUIRE( sol.pos == std::vector<size_t>{ 0 } );
}

