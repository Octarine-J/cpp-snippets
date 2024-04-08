#include <catch2/catch_test_macros.hpp>

// functor is a callable object
template<class T>
class less_then {
    T value;
public:
    explicit less_then(const T& t) : value(t) {}
    bool operator()(const T& t) {
        return t < value;
    }
};

TEST_CASE( "less_then Functor" ) {
    less_then lt {7};

    REQUIRE( lt(6) );
    REQUIRE( ! lt(8) );
}

