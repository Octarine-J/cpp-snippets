#ifndef ALGORITHMS_COUNT_OPERATIONS_HPP
#define ALGORITHMS_COUNT_OPERATIONS_HPP

#include <iomanip>
#include <numeric>
#include <ostream>
#include <random>
#include <vector>

#include "instrumented.hpp"

void print_header(std::ostream& os, int field_width = 12) {
    os << std::left;
    for (auto counter_name : instrumented_base::counter_names) {
        os << std::setw(field_width) << counter_name;
    }
    os << std::endl;
}

void print_metrics(std::ostream& os, int output_precision = 3, int field_width = 12) {
    os << std::fixed << std::setprecision(output_precision);
    for (auto metric : instrumented_base::counts) {
        os << std::setw(field_width) << metric;
    }
    os << std::endl;
}

auto random_double_vector(size_t n) -> std::vector<instrumented<double>> {
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::vector<instrumented<double>> v(n);

    std::iota(v.begin(), v.end(), 0.0);
    std::shuffle(v.begin(), v.end(), generator);

    return v;
}

// counts how many basic operations of a regular type are invoked
// when a function f acts on a container of n elements
template<typename Container, typename Function>
void count_operations(std::ostream& os, Container& container, Function f) {
    // print header
    print_header(os);

    // run some code for evaluation
    instrumented_base::initialize(container.size());  // size of input
    f(container.begin(), container.end());

    // output metrics (how many times each operation was invoked)
    print_metrics(os);
}

template<typename Function>
void count_operations_n(std::ostream& os, size_t n, size_t n_max, Function f) {
    // print header
    print_header(os);

    for (size_t i = n; i <= n_max; i <<= 1) {
        auto v = random_double_vector(i);
        instrumented_base::initialize(i);  // size of input

        // run some code for evaluation
        f(v.begin(), v.end());

        // output metrics (how many times each operation was invoked)
        print_metrics(os, 0);
    }
}

#endif
