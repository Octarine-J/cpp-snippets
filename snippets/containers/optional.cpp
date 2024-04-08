#include <optional>
#include <vector>

#include <catch2/catch_test_macros.hpp>


// a typical linear search function
template<class T>
std::optional<size_t> find(const std::vector<T>& v, const T& n) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == n) {
            return { i };  // same as "return std::optional<size_t> { i }"
        }
    }
    return {};  // equivalent to std::nullopt
}

TEST_CASE( "Optional" ) {
    std::vector<int> nums = {1, 2, 3};

    REQUIRE( find(nums, 3).has_value() );
    REQUIRE( find(nums, 3).value() == 2 );
    REQUIRE( find(nums, 3).value_or(-1) == 2 );

    REQUIRE( ! find(nums, 4).has_value() );
    REQUIRE( find(nums, 4).value_or(-1) == -1 );
}
