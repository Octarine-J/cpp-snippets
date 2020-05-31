#include <iostream>

int x = 42;

int main() {
    std::cout << "x = " << x << std::endl;

    int x = 12;
    std::cout << "x = " << x << std::endl;

    // using global scope operator
    std::cout << "x = " << ::x << std::endl;

    return 0;
}
