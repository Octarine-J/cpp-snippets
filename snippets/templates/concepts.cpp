#include <concepts>

#include <catch2/catch_test_macros.hpp>

// concepts are constrained template types
template<std::copyable T>  // using a predefined concept from the standard library
T foo(T& value) {
    // can overload foo for different concepts
    // the compiler will choose the overloaded function that better matches the requirements
    T a {value};
    return a;
}

class NonCopyable {
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable& other) = delete;
};

TEST_CASE( "Constrained Template Instantiation" ) {
    int x = 7;
    REQUIRE( foo(x) == x );  // OK

    NonCopyable y;
    //foo(y);  // does not compile, y is not copyable
}
