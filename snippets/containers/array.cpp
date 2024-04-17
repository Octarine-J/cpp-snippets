#include <array>
#include <cstring>
#include <iterator>
#include <memory>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Array Creation" ) {
    std::array<double, 3> values {};  // zero-init

    REQUIRE( values.size() == 3 );
    REQUIRE( values[2] == 0 );
}

TEST_CASE( "Array Iteration" ) {
    std::array<int, 3> values {1, 2, 3};

    // using iterators (requires the <iterator> header)
    for (auto it = std::begin(values); it != std::end(values); ++it) {
        REQUIRE( *it < 5 );
    }


    // using for-range loop
    for (auto& value : values) {
        REQUIRE( value < 5 );
    }
}

TEST_CASE( "Array Comparison" ) {
    std::array<double, 3> values = {1.0, 1.5, 2.0};
    std::array<double, 3> values_copy = {1.0, 1.5, 2.0};

    // modern arrays can be compared with just ==
    REQUIRE( values == values_copy );

    values_copy[2] = 1.7;
    REQUIRE( values != values_copy );
}

TEST_CASE( "C-Style Array on Stack" ) {
    int arr[10] {};     // a zero-initialized fixed-size array on stack
    int(*p)[10] = &arr; // a pointer to an array of size 10
    int(&a)[10] = arr;  // a reference to an array of size 10

    REQUIRE( (*p)[5] == 0 );

    // number of elements in the array (C++17)
    REQUIRE( std::size(a) == 10 );

    // size of the entire array, in bytes
    REQUIRE( sizeof a == 10 * (sizeof a[0]) );
}

TEST_CASE( "C-Style Free Store Buffer" ) {
    constexpr auto MSG_SIZE = 24;
    std::unique_ptr<char[]> msg = std::make_unique<char[]>(MSG_SIZE);

    // clearing the contents
    std::memset(msg.get(), 0, MSG_SIZE);
    REQUIRE( msg[12] == 0);
}

TEST_CASE( "Structured Bindings for Arrays (C++17)" ) {
    std::array<int, 3> nums {100, 200, 300};
    auto [n1, n2, n3] = nums;

    REQUIRE( n1 == 100 );
    REQUIRE( n2 == 200 );
    REQUIRE( n3 == 300 );
}

TEST_CASE( "Two-Dimensional Array" ) {
    int arr[3][4] {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 1, 2, 3}
    };

    // need to use references to iterate over multidimensional arrays,
    // except the most inner loop:
    for (const auto &row : arr) {
        for (auto value : row) {
            REQUIRE( value < 10 );
        }
    }
}
