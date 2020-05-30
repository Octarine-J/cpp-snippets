#include <iostream>

// function type alias
using Predicate = bool (*)(const int &, const int &);

// a function
bool compare(const int &a, const int &b) {
    return a == b;
}

int main() {
    // a function pointer
    bool (*p)(const int &, const int &); // uninitialized
    p = compare;

    std::cout << p(3, 4) << std::endl;

    Predicate p2 = compare;
    std::cout << p2(7, 7) << std::endl;

    return 0;
}
