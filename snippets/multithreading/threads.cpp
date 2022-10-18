#include <thread>
using namespace std::chrono;

#include <catch2/catch_test_macros.hpp>


void worker(int* sum, const int arg) {
    // sleep
    std::this_thread::sleep_for(milliseconds(10 * arg));

    (*sum) += arg;  // data race
}

TEST_CASE( "Threads and Shared Memory" ) {
    // measure thread execution time
    auto start = high_resolution_clock::now();

    int sum = 0;
    std::thread t1(worker, &sum, 10);
    std::thread t2(worker, &sum, 20);

    t1.join();
    t2.join();

    // time delta
    auto finish = high_resolution_clock::now();
    auto delta = duration_cast<milliseconds>(finish - start);

    REQUIRE( sum == 30 );
    REQUIRE( delta.count() < 2000 );  // thread execution time, in milliseconds
}
