#include <iostream>
#include <utility>

// const by default is local to the current file,
// add 'extern' to share it between files
extern const int BUF_SIZE = 200;

// mark a function as constexpr to be able to use it in constant expressions
constexpr double square(double x) {
    return x * x;
}

int main() {
    // we must use 'references to const' for const objects
    const int x = 12;
    const int &xref = x; // error happens if we omit 'const'

    // 'references to const' can be bound to a literal...
    const int &lref = 42;
    // or even to an expression.
    const int &eref = x * lref;
    std::cout << eref << std::endl;

    // 'pointer to const' can't be used to change the object
    const int *px = &x; // error happends if we omit 'const' (since x is const)

    // a pointer that is const itself
    int y = 10;
    int *const py = &y;
    // constant pointer to a constant object
    const int *const cpy = &y;

    // while const simply means that a value cannot be changed,
    // constexpr guarantees that a value is evaluated at compile time,
    // so it can be put in read-only memory
    const int z = 200;
    constexpr int ez = z * 2;
    constexpr double sq = square(4.0);

    // get a const version of an object
    int w = 100;
    const int &wa = std::as_const(w);

    // the same can be accomplished with
    const int &wb = const_cast<const int &>(w);

    // const_cast can also remove constness
    int &wc = const_cast<int &>(wa);

    return 0;
}
