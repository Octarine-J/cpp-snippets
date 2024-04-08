#include <catch2/catch_test_macros.hpp>


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
