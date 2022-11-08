#include <sstream>

#include <catch2/catch_test_macros.hpp>

// Method 1: pre C++20

// variadic template (base case, must be declared first)
template <typename T>
void print_all(std::ostream& os, T value) {
    os << value;
}

// variadic template (list of values of different types)
template <typename T, typename ...Rest>
void print_all(std::ostream& os, T head, Rest... tail) {  // function must have the same name
    os << head << " ";
    print_all(os, tail...);  // recursive call
}

// Method 2: using if-constexpr

template <typename T, typename ...Rest>
void print_all_v2(std::ostream& os, T head, Rest... tail) {
    os << head << " ";
    if constexpr (sizeof...(tail) > 0) {
        print_all_v2(os, tail...);  // recursive call
    }
}

// Method 3: using fold

template <typename... Rest>
void print_all_v3(std::ostream& os, Rest&&... tail) {
    (os << ... << tail);
}

TEST_CASE( "Variadic Templates" ) {
    std::stringstream ss;

    print_all(ss, 3.0, 22, "bread", true);
    REQUIRE( ss.str() == "3 22 bread 1" );

    ss.str("");
    print_all_v2(ss, 3.0, 22, "bread", true);
    REQUIRE( ss.str() == "3 22 bread 1 " );  // extra space in the end

    ss.str("");
    print_all_v3(ss, 3.0, 22, "bread", true);
    REQUIRE( ss.str() == "322bread1" );
}
