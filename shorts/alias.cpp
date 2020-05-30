#include <iostream>

int main() {
    typedef double *pdouble;  // old confusing style, don't use anymore
    pdouble p = nullptr;

    using mydouble = double;  // C++11
    mydouble x = 42;

    return 0;
}
