#include <type_traits>

#include <catch2/catch_test_macros.hpp>

// use if-constexpr for compile time template tuning
// very useful with concepts
// can optimize code for types that have particular traits
template <typename T>
T foo(const T& value) {
    if constexpr (std::is_copy_constructible<T>::value) {
        T result(value);
        return result;
    } else {
        return {};
    }
}

TEST_CASE( "if constexpr" ) {
    struct Test {
        Test() = default;
        Test(const Test&) = delete;
    };
    Test test;

    REQUIRE( foo(4) == 4);

    foo(test);
}
