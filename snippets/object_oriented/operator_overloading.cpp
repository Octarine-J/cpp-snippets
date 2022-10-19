#include <string>

#include <catch2/catch_test_macros.hpp>

class Box {
    int m_value;
public:
    Box(int value) : m_value{value} {}

    friend std::ostream& operator<<(std::ostream&, const Box&);
    friend Box operator+(const Box&, const Box&);
    friend bool operator==(const Box&, const Box&);

    // shorthand operators must return a reference
    // usually declared within a class
    Box& operator+=(const Box& other) {
        m_value += other.m_value;
        return *this;
    }

    // unary minus operator: creates a new object
    Box operator-() const {
        return Box {-m_value};
    }

    // prefix increment: returns a reference
    Box& operator++() {
        ++m_value;
        return *this;
    }

    // postfix increment: returns the old value
    Box operator++(int) {  // C++ hack: unused int parameter to distinguish from prefix operator
        auto old_box(*this);
        ++(*this);
        return old_box;
    }

    // conversion operator (to string)
    operator std::string() const {
        return std::to_string(m_value);
    }

    // can use Box as a function object (functor)
    bool operator()(int value) const {
        return m_value == value;
    }
};

std::ostream& operator<<(std::ostream& stream, const Box& box) {
    return stream << box.m_value;
}

// must be declared outside the class to allow commutativity (both: value + box and box + value)
Box operator+(const Box& first, const Box& second) {
    // can be implemented in terms of += to avoid code duplication
    return { first.m_value + second.m_value };
}

bool operator==(const Box& first, const Box& second) {
    return first.m_value == second.m_value;
}

TEST_CASE( "Operator Overloading" ) {
    Box x {42};
    x += 10;  // implicit call of Box(int value)

    REQUIRE( x == 52 );

    Box y = -x + 100;
    REQUIRE( y == 48 );

    Box z {52};
    REQUIRE( x == z );

    Box w {100};
    REQUIRE( w(100) );  // as functor, returns true if the value matches
    REQUIRE( not w(99) );

    std::string s = w;  // using conversion operator
    REQUIRE( s == "100" );
}
