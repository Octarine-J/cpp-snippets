#include <functional>
#include <iostream>
#include <sstream>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"

void for_each(std::vector<int>& v, const std::function<void(int&)>& f) {
    for (auto& item : v) {
        f(item);
    }
}

TEST_CASE( "Lambda without Parameters" ) {
    auto f = []{
        return std::string("hello, world");
    };

    REQUIRE( f() == "hello, world" );
}

TEST_CASE( "Closure" ) {
    int sum = 0;
    std::vector<int> v = {1, 2, 3};

    for_each(v, [&sum](int value) {
        sum += value;
    });

    REQUIRE( sum == 6 );
}

TEST_CASE( "Modifying a Vector by Lambda" ) {
    std::vector<int> v = {1, 2, 3};

    for_each(v, [](int& value) {
        value *= 2;
    });

    REQUIRE( v == std::vector<int>{2, 4, 6} );
}

TEST_CASE( "Partial Application Using Bind" ) {
    std::stringstream ss;

    auto f = [&ss](auto& value) {
        ss << value << " ";
    };

    auto my_print = std::bind(for_each, std::placeholders::_1, f);

    // can now call for_each with just one argument
    std::vector<int> v = {1, 2, 3};
    my_print(v);

    REQUIRE( ss.str() == "1 2 3 " );
}

TEST_CASE( "Partial Application Using Bind (with References)" ) {
    auto inc = [](int& x) {
        ++x;
    };

    // if we use plain bind, we get a copy of a parameter so it wont be incremented..
    int i = 0;
    auto my_inc = std::bind(inc, i);

    my_inc();
    REQUIRE( i == 0 );

    // we need to use std::ref to properly bind a reference
    auto my_inc_real = std::bind(inc, std::ref(i));

    my_inc_real();
    REQUIRE( i == 1 );
}

TEST_CASE( "Swap Function Parameters Using Bind" ) {
    auto f = [](int x, int y) {
        return x - y;
    };

    auto g = std::bind(f, std::placeholders::_2, std::placeholders::_1);

    REQUIRE( f(3, 4) == -1 );
    REQUIRE( g(3, 4) == 1 );
}

TEST_CASE( "Invoke" ) {
    auto f = [](const std::string& name){
        return "hello, " + name;
    };

    // invoke a function
    REQUIRE( std::invoke(f, "user") == "hello, user" );

    // invoke a member function
    std::string s = "hi";
    size_t sz = std::invoke(&std::string::size, s);

    REQUIRE( sz == 2 );
}
