#include <catch2/catch_test_macros.hpp>

class Box {
private:
    int value_;
public:
    explicit Box(int value) : value_(value) {}

    // can call this method only on non-temporary (named) objects
    [[nodiscard]] int get_value() const & {
        return value_;
    }

    // can call this method only on temporary objects
    [[nodiscard]] int get_value() const && {
        return value_ * 2;
    }
};

TEST_CASE( "Ref Methods" ) {
    Box box {7};

    REQUIRE( box.get_value() == 7 );  // calls first method

    REQUIRE( (Box {9}).get_value() == 18 );  // calls second method
}
