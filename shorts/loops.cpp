#include <iostream>

int main() {
    // can use initializer list as an expression
    for (auto value : {10, 11, 13, 16, 20}) {
        std::cout << value << std::endl;
    }
}
