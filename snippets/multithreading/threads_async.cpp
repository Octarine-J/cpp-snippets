#include <future>
#include <numeric>
#include <vector>

#include <catch2/catch_test_macros.hpp>


int add(std::vector<int>::const_iterator begin,
        std::vector<int>::const_iterator end,
        int init_value) {
    return std::accumulate(begin, end, init_value);
}

TEST_CASE( "Async" ) {
    std::vector<int> vec {10, 14, 13, 7, 8, 15};
    auto mid = vec.cbegin() + (vec.cend() - vec.cbegin()) / 2;

    std::future<int> f = std::async(add, vec.cbegin(), mid, 0);
    std::future<int> g = std::async(add, mid, vec.cend(), 0);

    int result = f.get() + g.get();

    REQUIRE( result == 67 );
}
