#include <cmath>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

template <typename T = int>  // can provide default type
class Box {
private:
    T value;
public:
    Box(const T& _value) : value{_value} {}

    const T& get_value() const;

    // default copy constructor
    Box(const Box& other) = default;

    // copy constructor from a box parameterized by another type
    template <typename E>
    Box(const Box<E>& other);
};

template <typename T>
const T& Box<T>::get_value() const {
    return value;
}

template <typename T>  // class template comes first
template <typename E>
Box<T>::Box(const Box<E>& other) {
    this->value = other.get_value();
}

// custom type deduction rule for the template:
Box(const char*) -> Box<std::string>;


TEST_CASE( "Class Templates" ) {
    const double eps = 1e-7;

    Box<std::string> box1 {"test"};
    REQUIRE( box1.get_value() == "test" );

    Box<double> box2 {3.14};
    REQUIRE( fabs(box2.get_value() - 3.14) < eps );

    Box<std::vector<int>> box3 {{1, 2, 3}};

    Box<> box4 {42};  // using default type
    REQUIRE( box4.get_value() == 42 );

    Box box5 {2.71};  // C++17: compiler can deduce the type from constructor arguments
    REQUIRE( fabs(box5.get_value() - 2.71) < eps );

    Box<int> box6(Box<double>(2.17));  // using templated copy constructor
    REQUIRE( box6.get_value() == 2 );
}
