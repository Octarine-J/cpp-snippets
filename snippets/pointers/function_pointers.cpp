#include <catch2/catch_test_macros.hpp>

// function type alias
using Predicate = bool (*)(const int &, const int &);

// a function
bool compare_f(const int &a, const int &b) {
    return a == b;
}

TEST_CASE( "Function Pointers") {
    // a function pointer
    bool (*p)(const int &, const int &);  // uninitialized
    p = compare_f;

    REQUIRE( ! p(3, 4) );

    Predicate p2 = compare_f;
    REQUIRE( p2(7, 7) );
}
