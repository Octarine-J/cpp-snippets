#include <iostream>

int main() {
    std::cout << "hello, world";
    std::cout << std::endl; // flushes the buffer!

    std::cerr << "An error message goes to std::cerr" << std::endl;
    std::clog << "std::clog stream is used for logging" << std::endl;

    return -1;
}
