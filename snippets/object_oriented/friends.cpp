#include <catch2/catch_test_macros.hpp>

class Foo {
    int m_value;
    friend class Bar;  // class Bar now have access to private members of Foo
    friend void set_foo_value(Foo&, int value);  // friend free function
public:
    explicit Foo(int value) : m_value(value) {}

    int get_value() const {
        return m_value;
    }
};

class Bar {
public:
    void reset_value(Foo& foo) {
        foo.m_value = 0;
    }
};

void set_foo_value(Foo& foo, int value) {
    foo.m_value = value;
}

TEST_CASE( "Friends" ) {
    Foo foo(42);

    Bar bar;
    bar.reset_value(foo);

    REQUIRE( foo.get_value() == 0 );

    set_foo_value(foo, 15);
    REQUIRE( foo.get_value() == 15 );
}
