#include <iostream>

int f(double x) {
    return x * x;
}

int main() {
    // deduce type, but do not evaluate the expression
    decltype(f(3.14)) a{17}; // a is deduced as having type 'int'

    // decltype yields a _reference_ type if its argument is lvalue
    int *p;
    decltype(*p) b = a; // b is int&
    a = 42;
    std::cout << b << std::endl;

    return 0;
}
