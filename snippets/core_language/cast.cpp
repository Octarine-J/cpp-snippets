#include <bit>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "bit cast" ) {
    // C++20: creates a new object from bits of other object
    // works for trivially copyable types only
    float a = 2.8f;
    int b = std::bit_cast<int>(a);

    REQUIRE( b == 1077097267 );
}

TEST_CASE( "Reinterpret Cast" ) {
    // unsafe casting of pointers between unrelated classes
    class A {};

    // ex.: A* and void* are unrelated
    A a;
    A* ptr = &a;
    void* v_ptr = ptr;  // OK, no cast required

    // not OK, must use reinterpret_cast
    A* result = reinterpret_cast<A*>(v_ptr);
    REQUIRE( result == ptr );
}
