#include <algorithm>
#include <execution>
#include <functional>
#include <numeric>
#include <vector>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Sum" ) {
    std::vector<int> v {1, 5, 3, 7};

    int sum = std::accumulate(v.begin(), v.end(), 0);

    REQUIRE( sum == 16 );
}

TEST_CASE( "Sum (Parallel)" ) {
    std::vector<int> v {1, 5, 3, 7};

    int sum = std::reduce(std::execution::par_unseq, v.begin(), v.end(), 0);

    REQUIRE( sum == 16 );
}

TEST_CASE( "Product" ) {
    std::vector<int> v {1, 5, 3, 7};

    int product = std::accumulate(v.begin(), v.end(), 1,
                                  [](int x, int y) {
                                      return x * y;
                                  });
    REQUIRE( product == 105 );

    // can use a functor instead of a lambda
    // can omit template parameter to be inferred based on the identity type (1 vs 1.0)
    int product2 = std::accumulate(v.begin(), v.end(), 1, std::multiplies<>());
    REQUIRE( product2 == 105 );
}

TEST_CASE( "Boolean And" ) {
    std::vector<bool> v {true, true, true};

    auto my_and = [](const std::vector<bool>& v) {
        return std::accumulate(v.begin(), v.end(), true, std::logical_and<>());
    };
    REQUIRE( my_and(v) == true );

    v.push_back(false);
    REQUIRE( my_and(v) == false );
}

TEST_CASE( "Boolean And (using the Standard Algorithm" ) {
    std::vector<int> v {2, 4, 6, 8};

    bool all_even = std::all_of(v.begin(), v.end(),
                                [](int value) {
                                    return value % 2 == 0;
                                });
    REQUIRE( all_even );
}

TEST_CASE( "Boolean Or (using the Standard Algorithm" ) {
    std::vector<int> v {1, 4, 3, 7};

    bool has_even = std::any_of(v.begin(), v.end(),
                                [](int value) {
                                    return value % 2 == 0;
                                });
    REQUIRE( has_even );
}

TEST_CASE( "Inner Product" ) {
    std::vector<int> a {1, 2, 3};
    std::vector<int> b {3, 0, 7};

    int result = std::inner_product(a.begin(), a.end(), b.begin(), 0);
    REQUIRE( result == 24 );
}
