#include <catch2/catch_test_macros.hpp>


// strongly typed enum; can set underlying type
enum class Colors : short {
    Red = 1, Orange, Yellow, Green, Blue, Indigo, Violet
};

TEST_CASE( "Enums" ) {
    auto color = Colors::Green;

    REQUIRE( color != Colors::Indigo );
}

TEST_CASE( "Enums in Switch Statement" ) {
    auto x = Colors::Yellow;

    switch (x) {
        case Colors::Red:
        case Colors::Orange:
        case Colors::Yellow:
            REQUIRE( x == Colors::Yellow );
            break;
        case Colors::Blue:
        case Colors::Green:
        case Colors::Indigo:
        case Colors::Violet:
            REQUIRE( x == Colors::Blue );
            break;
    }
}
