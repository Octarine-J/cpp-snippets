#include <catch2/catch_test_macros.hpp>


int sqr_test(int x) {
    return x * x;
};

TEST_CASE( "If Statement" ) {
    // C++17: if-statement with initializer
    if (int value = sqr_test(3); value >= 2) {
        REQUIRE( value >= 2 );
    }
}

TEST_CASE( "Switch Statement" ) {
    // C++17: switch-statement with initializer
    switch (int value = sqr_test(3); value - 7) {
        case 1:
        case 2:
            REQUIRE( value == 9 );
            [[fallthrough]];  // C++17: intentional fallthrough
        case 42:
            // executed for 1, 2, or 42
            REQUIRE( value == 9 );
    }
}

TEST_CASE( "For Loop" ) {
    // can use initializer list as an expression
    for (auto value : {10, 11, 13, 16, 20}) {
        REQUIRE( value <= 20 );
    }

    // use a reference to modify each item in a list
    int a[] = {1, 2, 3};
    for (auto& value : a) {
        ++value;
    }

    REQUIRE( (a[0] == 2 and a[1] == 3 and a[2] == 4) );
}
