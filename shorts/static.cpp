#include <iostream>
#include <string>

std::string func() {
    // initialized before the first call of the function
    static int called_times = 0;
    return std::string("The function is called " + std::to_string(++called_times) + " times.");
}

int main() {
    for (int i = 0; i < 7; ++i) {
        std::cout << func() << std::endl;
    }

    return 0;
}
