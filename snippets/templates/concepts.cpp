#include <concepts>

#include <catch2/catch_test_macros.hpp>

// concepts are constrained template types
template<std::copyable T>  // using a predefined concept from the standard library
T foo(T& value) {
    T a {value};
    return a;
}

class NonCopyable {
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable& other) = delete;
};

TEST_CASE( "Constrained Template Instantiation" ) {
    int x;
    REQUIRE( foo(x) == x );  // OK

    NonCopyable y;
    //REQUIRE( foo(y) == y );  // does not compile, y is not copyable
}
