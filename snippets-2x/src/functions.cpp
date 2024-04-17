#include <catch2/catch_test_macros.hpp>

// a constexpr function, may be evaluated at compile time
constexpr int cf() {
    return 42;
}

// C++20: a consteval function, MUST be evaluated at compile time
consteval int cg() {
    return cf() * 42;
}

TEST_CASE( "Consteval Function" ) {
    constexpr int my_const = cf();
    REQUIRE( my_const == 42 );

    constexpr int my_const2 = cg();
    REQUIRE( my_const2 == 1764 );
}
