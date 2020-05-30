#include <iostream>

int get_value() {
    return 42;
}

int main() {
    // C++17: if-statement with initializer
    if (int val = get_value(); val >= 42) {
        std::cout << "success" << std::endl;
    }

    // C++17: switch-statement with initializer
    switch (int value = get_value(); value - 40) {
        case 1:
        case 2:
            std::cout << "initial" << std::endl;
            [[fallthrough]]; // C++17: intentional fallthrough
        case 42:
            // DANGER: executed for 1, 2, or 42 
            std::cout << "final";
    }
}
