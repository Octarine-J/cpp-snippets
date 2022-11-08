#include <map>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

template <typename T>
decltype(auto) sum(std::vector<T> v, T acc = {}) {  // automatically deduce return type and preserve constness
    for (T &e : v) {
        acc = acc + e;
    }
    return acc;
}

// C++14: variable template
template <typename T>
const T pi = T(3.1415926);

// alias template
template <typename T>
using string_map = std::map<std::string, T>;

TEST_CASE( "Templates" ) {
    std::vector<double> a {1.23, 3.14, 7.23, 9.92};
    REQUIRE( (sum(a) - 21.52 < 1e-5) );

    std::vector<int> b {1, 2, 3};
    REQUIRE( sum(b) == 6 );

    std::vector<std::string> c {"Hello", ", ", "world", "!"};
    REQUIRE( sum(c) == "Hello, world!" );

    float floatPi = pi<float>;
    double doublePi = pi<double>;

    REQUIRE( (floatPi - doublePi < 1e-3) );

    string_map<int> m;
    m["one"] = 1;
    REQUIRE( m["one"] == 1 );
}
