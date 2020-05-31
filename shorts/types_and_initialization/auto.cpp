#include <iostream>

int main() {
    const int x = 7;

    auto y = x;
    ++y; // auto strips const modifiers

    decltype(x) z = x; // decltype preserves const modifier
}
