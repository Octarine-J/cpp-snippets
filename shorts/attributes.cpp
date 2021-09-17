#include <cstdlib>
#include <iostream>

// function never returns
[[noreturn]] void exit_app() {
    std::exit(1);
}

// deprecation
[[deprecated("unsafe, use bar() instead")]] void foo(int i) {
    switch (i) {
        case 0:
            std::cout << i << std::endl;
            [[fallthrough]];  // C++17: intentional fallthrough
        case 1:
            std::cout << i << std::endl;
            break;
        default:
            break;
    }
}

// a caller must use the result of this function
[[nodiscard]] int square(int x) {
    return x * x;
}

// suppress warning for an unused parameter
int get_param(int p1, [[maybe_unused]] int p2) {
    return p1;
}

int main() {
    foo(1);  // generates a complier warning
}
