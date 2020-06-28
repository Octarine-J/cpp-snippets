#include <array>
#include <cmath>
#include <ctime>
#include <fstream>
#include <random>
#include <unordered_map>


int main() {
    std::random_device rd;
    auto seed = rd.entropy() ? rd() : std::time(nullptr);
    std::mt19937 engine(static_cast<std::mt19937::result_type>(seed));

    std::normal_distribution distribution(50.0, 10.0);  // mean, standard deviation
    
    constexpr size_t num_trials = 1'000'000;
    constexpr int x_start = 0;
    constexpr int x_end = 100;
    constexpr double bucket_size = 0.1;
    constexpr int num_buckets = static_cast<int>((x_end - x_start) / bucket_size);
    std::array<int, num_buckets> result = {};

    constexpr double m = 1.0 / bucket_size;
    
    for (size_t i = 0; i < num_trials; ++i) {
        double r = distribution(engine);
        int bucket = static_cast<int>(std::round(r * m));

        if (bucket < num_buckets) {
            result[bucket] += 1;
        }
    }

    std::ofstream f("normal_dist.csv");

    double x = x_start;
    for (int i = 0; i < num_buckets; ++i) {
        f << x << "," << result[i] << "\n";
        x += bucket_size;
    }
}
