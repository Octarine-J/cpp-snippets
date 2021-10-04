#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include "../data_structures/matrix.hpp"

/**
 * A classical knapsack problem:
 * sum( w_i * x_i ) <= K,  x_i = {0, 1}
 * sum( v_i * x_i ) -> max
 */
namespace alg::opt::knapsack {
    struct item {
        int value;   // v_i
        int weight;  // w_i

        friend bool operator==(const item& a, const item& b) {
            return a.value == b.value && a.weight == b.weight;
        }
    };

    struct solution {
        int max_value;
        std::vector<size_t> pos;
    };

    solution optimal_fit(const std::vector<item>& items, int capacity) {
        if (capacity <= 0) {
            return {};
        }

        size_t n = items.size();
        if (n == 0) {
            return {};
        }

        // two extra rows for border conditions:
        // first row: 0 items, first column: 0 capacity
        ds::matrix<int> optimal(1 + n, 1 + capacity);
        optimal.set_row(0u, 0);

        for (int i = 1; i <= n; ++i) {
            const item& current_item = items[i - 1];  // row 1 is for the first item

            for (int j = 0; j <= capacity; ++j) {
                // if the current item fits
                if (j - current_item.weight >= 0) {
                    optimal(i, j) = std::max(
                        current_item.value + optimal(i - 1, j - current_item.weight),
                        optimal(i - 1, j)
                    );
                } else {
                    // current item does not fit, so it makes no difference
                    optimal(i, j) = optimal(i - 1, j);
                }
            }
        }

        // backtrack to get indexes
        std::vector<size_t> pos;
        int i = n;
        int j = capacity;

        while (i > 0 && j >= 0) {
            if (optimal(i, j) != optimal(i - 1, j)) {
                pos.push_back(i - 1);
                j -= items[i - 1].weight;
            }
            
            i -= 1;
        }

        std::reverse(pos.begin(), pos.end());

        int max_value = optimal(n, capacity);
        return { max_value, pos };
    }
}
