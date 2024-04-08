#include <catch2/catch_test_macros.hpp>

template<typename T>
concept eq_comparable =
        requires (T x, T y) {
            // code listed here must compile for concept to be applicable to T
            x == y;
            x != y;
        };

TEST_CASE( "User-Defined Concepts" ) {
    struct S { int a; };

    // concepts evaluate to bool
    REQUIRE( eq_comparable<int> );
    REQUIRE( not eq_comparable<S> );  // structs don't define == by default
}

// template function that accepts any parameter that matches the concept
// auto keyword is required after the concept name
eq_comparable auto concept_foo(eq_comparable auto& x) {
    return x;
}

// eventually most functions will be defined as template functions
// with their arguments constrained by concepts

TEST_CASE( "Concept Template Function" ) {
    int x = 4;
    REQUIRE( concept_foo(x) == 4 );
}
