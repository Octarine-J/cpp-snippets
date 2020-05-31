#include <iostream>

// Sums unknown number of arguments.
int main() {
    int sum = 0;
    int value;

    // The result of expression "std::cin >> value" is "std::cin";
    // the state of the stream is tested;
    // the state becomes invalid (false), if there's EOF or
    // an input error occurred (i.e. reading a value that's not a number).
    while (std::cin >> value) {
        sum += value;
    }

    std::cout << "sum = " << sum << std::endl;
    std::cout << "cin stream state = " << (bool)std::cin << std::endl;
    std::cout << "cout stream state = " << (bool)std::cout << std::endl;
    return 0;
}
