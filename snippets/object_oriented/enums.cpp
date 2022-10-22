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
    using enum Colors;  // to avoid repetition in switch

    auto x = Yellow;

    switch (x) {
        case Red:
        case Orange:
        case Yellow:
            REQUIRE( x == Yellow );
            break;
        case Blue:
        case Green:
        case Indigo:
        case Violet:
            REQUIRE( x == Blue );
    }
}
