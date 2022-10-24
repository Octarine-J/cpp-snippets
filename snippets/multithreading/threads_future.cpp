#include <future>
#include <numeric>
#include <thread>
#include <vector>

#include <catch2/catch_test_macros.hpp>


int add_all(std::vector<int>::const_iterator begin,
            std::vector<int>::const_iterator end,
            int init_value) {
    return std::accumulate(begin, end, init_value);
}

TEST_CASE( "Packaged Task and Future" ) {
    using add_type = decltype(add_all);

    std::packaged_task<add_type> task1(add_all);
    std::future<int> result1(task1.get_future());

    std::packaged_task<add_type> task2(add_all);
    std::future<int> result2(task2.get_future());

    std::vector<int> vec {10, 14, 13, 7, 8, 15};
    auto mid = vec.cbegin() + (vec.cend() - vec.cbegin()) / 2;

    std::thread t1(std::move(task1), vec.begin(), mid, 0);
    std::thread t2(std::move(task2), mid, vec.end(), 0);

    int result = result1.get() + result2.get();

    t1.join();
    t2.join();

    REQUIRE( result == 67 );
}
