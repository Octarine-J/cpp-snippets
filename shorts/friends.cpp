#include <iostream>

class Foo {
    int m_value;
    friend class Bar;  // class Bar now have access to private members of Foo
    friend void print_foo(const Foo&);  // friend free function
public:
    Foo(int value) : m_value(value) {}

    int get_value() { 
        return m_value;
    }
};

class Bar {
public:
    void reset_value(Foo& foo) {
        foo.m_value = 0;
    }
};

void print_foo(const Foo& foo) {
    std::cout << foo.m_value << std::endl;
}

int main() {
    Foo foo(42);

    Bar bar;
    bar.reset_value(foo);

    print_foo(foo);
}
