#include <chrono>
using namespace std::chrono;

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Add duration" ) {
    auto t = hours(1) + minutes(25) + seconds(10);
    seconds sec(t);  // convert to seconds

    REQUIRE( sec.count() == 5110 );
}

TEST_CASE( "Add duration (using literals)" ) {
    auto t = 1h + 25min + 10s;
    seconds sec(t);  // convert to seconds

    REQUIRE( sec.count() == 5110 );
}
