#include <iostream>

int main() {
    // assigning a larger type to a smaller one
    int val = static_cast<int>(3.141592);
    std::cout << val << std::endl;

    // convert pointers to void*
    void *p = &val;
    int *iptr = static_cast<int *>(p);
    std::cout << *iptr << std::endl;

    // remove constness
    const int *cptr = &val;
    //*cptr = 8;  // Error: cannot assign to const
    int *pptr = const_cast<int *>(cptr);
    *pptr = 65;          // OK
    std::cout << val << std::endl; // 65

    // convert to a bitwise-compatible type
    char *pc = reinterpret_cast<char *>(iptr);
    std::cout << *pc << std::endl; // first octet of that int, 'A'

    // dynamic_cast can be used for casting within the hierarchy
    // a class must have at least one virtual method
    class Base {
    public:
        virtual ~Base() = default;
    };

    class Derived : public Base {
    public:
        virtual ~Derived() = default;
    };

    Derived *derived = new Derived();
    Base *base = derived; // no cast needed

    derived = dynamic_cast<Derived*>(base); // need a cast to get derived from base

    std::cout << derived << std::endl;

    return 0;
}
