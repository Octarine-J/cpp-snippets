#include <functional>
#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 generator(rd());
    auto get_random = std::uniform_int_distribution<>(1, 6);

    for (int i = 0; i < 10; ++i) {
        std::cout << get_random(generator) << " ";
    }
    std::cout << std::endl;
}
