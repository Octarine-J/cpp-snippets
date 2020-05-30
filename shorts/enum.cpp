#include <iostream>

// strongly typed enum; can set underlying type
enum class Colors : short {
    Red = 1, Orange, Yellow, Green, Blue, Indigo, Violet
};

int main() {
    auto color = Colors::Green;
}
