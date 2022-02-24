#include <iostream>

int x = 42;

int main() {
    std::cout << "x = " << x << std::endl;    // 42

    int x = 12;
    std::cout << "x = " << x << std::endl;    // 12

    // using global scope operator
    std::cout << "x = " << ::x << std::endl;  // 42

    return 0;
}
