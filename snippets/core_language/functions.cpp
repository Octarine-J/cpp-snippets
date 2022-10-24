#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>


// It is recommended to always use 'references to const'
// when a function does not change its arguments.
bool contains_space(const std::string &s) {
    // __func__ returns current function name
    std::cout << "Executing function '" << __func__ << "'...\n";

    return std::ranges::any_of(s.begin(), s.end(),
                               [](char c) -> bool {
                                   return c == ' ';
                               });
}

// return an object initialized from an initializer list
std::vector<std::string> init_list_example() {
    return {"hello", "world", "!"};
}

// returns lvalue (see in the test)
std::string& f_ref(std::string &s) {
    return s;
}

// definition using trailing return type
auto my_square(int x) -> int {
    return x * x;
}

// a constexpr function, may be evaluated at compile time
constexpr int cf() {
    return 42;
}

// C++20: a consteval function, MUST be evaluated at compile time
consteval int cg() {
    return cf() * 42;
}

// functions cannot have array parameters, but they can have
// reference to array parameters
void print_array(const char (&arr)[4]) {
    for (size_t i = 0; i < 3; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// we can use this fact to get the number of elements in the array
template <typename T, size_t N>
constexpr size_t array_size(T (&)[N]) noexcept {
    return N;
}

TEST_CASE( "Functions" ) {
    REQUIRE( contains_space("hello world") );

    REQUIRE( init_list_example()[0] == "hello" );

    std::string s;
    f_ref(s) = "hi!"; // can assign to a function result if it is a lvalue
    REQUIRE( s == "hi!" );

    REQUIRE( my_square(7) == 49 );

    constexpr int my_const = cf();
    REQUIRE( my_const == 42 );

    constexpr int my_const2 = cg();
    REQUIRE( my_const2 == 1764 );

    const char str[] = "abc";  // const char[4]
    print_array(str);  // cannot call this function if the string above is longer or shorter

    REQUIRE( array_size(str) == 4 );
}
