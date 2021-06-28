#pragma once

#include <algorithm>
#include <ctime>
#include <functional>
#include <random>
#include <vector>

std::mt19937 make_engine() {
    std::random_device rd;
    const auto seed = static_cast<std::mt19937::result_type>(
        rd.entropy() ? rd() : std::time(nullptr));

    std::mt19937 engine(seed);
    return engine;
}

template <class T, class Random>
std::vector<T> random_vector(size_t n, const Random &get_random) {
    std::vector<T> result(n);
    std::generate(result.begin(), result.end(), get_random);
    return result;
}

std::vector<int> random_int_vector(size_t n, int lower_bound, int upper_bound) {
    auto distribution = std::uniform_int_distribution<>(lower_bound, upper_bound);
    auto engine = make_engine();
    auto get_random = std::bind(distribution, engine);

    return random_vector<int>(n, get_random);
}
