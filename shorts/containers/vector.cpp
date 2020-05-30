#include <functional>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"


// Vector may invalidate all iterators on insert
// Vector invalidates the current and all next iterators on erase

TEST_CASE( "Access Vector Elements" ) {
    std::vector<int> v = {4, 5, 6, 7, 8};

    REQUIRE( v.front() == 4 );  // first element
    REQUIRE( v.back() == 8 );   // last element

    REQUIRE( std::distance(v.begin(), v.end()) == 5 );  // distance between iterators

    // vector iterators are random access
    REQUIRE( *(v.begin() + 3) == 7 );
}

TEST_CASE( "Access Vector Elements with Range Check" ) {
    std::vector<int> v = {1, 2, 3};
    bool caught_exception = false;

    try {
        v.at(3);  // at does range checks
    } catch (const std::out_of_range& e) {
        caught_exception = true;
    }

    REQUIRE( caught_exception );
}

TEST_CASE( "Create a Vector" ) {
    // default-initialized vector of the given size:
    // built-in types get zero; class objects are created by the default constructor
    std::vector<int> u(10);
    REQUIRE( u[0] == 0 );
    REQUIRE( u[9] == 0 );

    // initialized vector of the given size
    std::vector<int> v(3, 255);

    REQUIRE( v.size() == 3 );
    REQUIRE( v[0] == 255 );
    REQUIRE( v[1] == 255 );
    REQUIRE( v[2] == 255 );

    // vector of two specified elements
    std::vector<int> w {3, 255};
    REQUIRE( w.size() == 2 );
    REQUIRE( w[0] == 3 );
    REQUIRE( w[1] == 255 );

    // as a partial copy of an array
    int arr[] = {1, 2, 3, 4, 5, 6};
    std::vector<int> z(arr + 1, arr + 4);
    REQUIRE( z.front() == 2 );
    REQUIRE( z.back() == 4 );
}

TEST_CASE( "Reuse a Vector (Assign)" ) {
    std::vector<int> v = {2, 4, 6, 8, 10, 12};
    size_t old_capacity = v.capacity();

    REQUIRE( v.size() == 6 );

    // reuse the vector: the vector is re-allocated only if new size exceeds previous size
    v.assign({1, 2});

    REQUIRE( v.size() == 2 );
    REQUIRE( v.capacity() == old_capacity );
}

TEST_CASE( "Exchange Contents of Two Vectors in O(1)" ) {
    std::vector<int> x(10, 1);
    std::vector<int> y(5, 2);

    x.swap(y);

    REQUIRE( x.size() == 5 );
    REQUIRE( x[0] == 2 );

    REQUIRE( y.size() == 10 );
    REQUIRE( y[0] == 1 );
}

TEST_CASE( "Compare Vectors" ) {
    std::vector<int> x = {1, 2, 3};
    std::vector<int> y = {1, 2, 3};
    std::vector<int> z = {1, 2, 4};

    REQUIRE( x == y );
    REQUIRE( x < z );
}

TEST_CASE( "Vector of References" ) {
    std::string s1 = "hello";
    std::string s2 = "world";

    std::vector<std::reference_wrapper<std::string>> v = { std::ref(s1), std::ref(s2) };

    v[1].get() += "!";  // can now modify s2 through the reference

    REQUIRE( s2 == "world!" );
}

TEST_CASE( "Add Values to a Vector" ) {
    std::vector v = {1, 2};

    v.push_back(3);
    REQUIRE( v.back() == 3 );

    v.pop_back();  // does not return the removed element
    REQUIRE( v.back() == 2 );

    // insert at the beginning
    v.insert(v.cbegin(), 7);
    REQUIRE( v.front() == 7 );

    // insert at the end
    v.insert(v.cend(), 42);
    REQUIRE( v.back() == 42 );

    // insert at position N
    const size_t n = 2;
    v.insert(v.cbegin() + n, 11);
    REQUIRE( v[n] == 11 );

    // insert all elements from another vector
    std::vector<int> z = {100, 200, 300};
    v.insert(v.cend(), z.cbegin(), z.cend());
    REQUIRE( v.back() == 300 );

    // insert 5 copies of value 42
    v.insert(v.cbegin(), 5, 42);
    REQUIRE( v.front() == 42 );
    REQUIRE( *(v.begin() + 4) == 42 );
}

TEST_CASE( "Removes Values from a Vector" ) {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // erase elements from 1 (inclusive) to 3 (exclusive)
    v.erase(v.cbegin() + 1, v.cbegin() + 3);

    REQUIRE( v.size() == 3 );
    REQUIRE( v == std::vector<int>({1, 4, 5}));

    // erase all elements
    v.clear();
    REQUIRE( v.empty() );
}

TEST_CASE( "Change All Elements in a Vector" ) {
    std::vector<int> v = {1, 2, 3};

    for (auto& value : v) {
        value *= 2;
    }

    REQUIRE( v[0] == 2 );
    REQUIRE( v[1] == 4 );
    REQUIRE( v[2] == 6 );
}

TEST_CASE( "Emplace" ) {
    std::vector<std::string> v;

    // construct an object in place (within the vector)
    v.emplace_back(5, 'a');

    REQUIRE( v.size() == 1 );
    REQUIRE( v.front() == "aaaaa" );
}
