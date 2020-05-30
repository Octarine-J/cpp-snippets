#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>


double sum(double* begin, double* end, double init) {
    return std::accumulate(begin, end, init);
}

int main() {
    using sum_type = double(double*, double*, double);

    std::packaged_task<sum_type> task1(sum);
    std::future<double> result1(task1.get_future());

    std::packaged_task<sum_type> task2(sum);
    std::future<double> result2(task2.get_future());

    std::vector<double> vec = {10, 14, 13, 7, 8, 15};
    double* ptr = &vec[0];

    std::thread t1(std::move(task1), ptr, ptr + vec.size() / 2, 0);
    std::thread t2(std::move(task2), ptr + vec.size() / 2, ptr + vec.size(), 0);

    auto result = result1.get() + result2.get();

    t1.join();
    t2.join();

    std::cout << "Result: " << result << std::endl;
}
