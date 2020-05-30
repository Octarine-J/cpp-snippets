#include <iostream>

int main() {
    // different ways to initialize an integer
    int a1 = 0;
    int a2 = {0};  // {} checks that value fits!
    int a3{0};     // same
    int a4(0);

    extern int b;  // declares, but not defines a variable
                   // no storage is allocated

    return 0;
}
