#include <iostream>

// C++17: shorthand declaration of nested namespaces
namespace my::nested::ns {
    void foo() {
        std::cout << "test\n";
    }
}

// namespace alias
namespace myns = my::nested::ns;

int main() {
    myns::foo();
}
