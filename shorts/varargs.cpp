#include <iostream>

// using an initializer list
void print_error(int code, std::initializer_list<std::string> args) {
    std::cout << "Error code: " << code << std::endl;
    for (const auto &arg : args) {
        std::cout << arg << std::endl;
    }
}

int main() {
    print_error(100, {"multiple", "arguments", "are", "passed"});
    print_error(200, {"two", "arguments"});

    return 0;
}
