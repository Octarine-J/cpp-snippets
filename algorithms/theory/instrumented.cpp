#include <algorithm>
#include "instrumented.hpp"

double instrumented_base::counts[];

void instrumented_base::initialize(size_t n) {
    std::fill(counts, counts + number_ops, 0.0);
    counts[n_] = static_cast<double>(n);
}

