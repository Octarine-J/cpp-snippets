#include <future>
#include <iostream>
#include <numeric>
#include <vector>


double sum(double* begin, double* end, double init) {
    return std::accumulate(begin, end, init);
}

int main() {
    std::vector<double> vec = {10, 14, 13, 7, 8, 15};
    double* ptr = &vec[0];

    auto f = std::async(sum, ptr, ptr + vec.size() / 2, 0);
    auto g = std::async(sum, ptr + vec.size() / 2, ptr + vec.size(), 0);

    auto result = f.get() + g.get();

    std::cout << "Result: " << result << std::endl;
}
