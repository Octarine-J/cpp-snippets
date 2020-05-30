#include <iostream>
#include <string>
#include <vector>

template <typename T = int>  // can provide default type
class Box {
private:
    const T value;
public:
    Box(T _value) : value{_value} {}

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


int main() {
    Box<std::string> box1 {"test"};
    std::cout << box1.get_value() << std::endl;

    Box<double> box2 {3.14};
    std::cout << box2.get_value() << std::endl;

    Box<std::vector<int>> box3 {{1, 2, 3}};

    Box<> box4 {42};  // using default type
    Box box5 {2.71};  // C++17: compiler can deduce the type from constructor arguments

    Box<int> box6(Box<double>(2.17));  // using templated copy constructor
}
