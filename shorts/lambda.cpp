#include <functional>
#include <iostream>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"

void for_each(std::vector<int>& v, const std::function<void(int&)>& f) {
    for (auto& item : v) {
        f(item);
    }
}

TEST_CASE( "Lambda without Parameters" ) {
    auto f1 = []{
        return "hello, world";
    };

    REQUIRE( f1() == "hello, world" );
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
