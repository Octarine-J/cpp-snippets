#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include "../data_structures/matrix.hpp"

namespace alg::opt::knapsack {
    struct item {
        int value;
        int weight;

        friend bool operator==(const item& a, const item& b) {
            return a.value == b.value && a.weight == b.weight;
        }
    };

    struct solution {
        int max_value;
        std::vector<size_t> pos;
    };

    solution optimal_fit(const std::vector<item>& items, int knapsack_size) {
        if (knapsack_size <= 0) {
            return {};
        }

        size_t n = items.size();
        if (n == 0) {
            return {};
        }

        ds::matrix<int> optimal(n, 1 + knapsack_size);

        // init the first row
        const item& first_item = items[0];
        for (int j = 0; j <= knapsack_size; ++j) {
            if (first_item.weight <= j) {
                optimal(0, j) = first_item.value;
            } else {
                optimal(0, j) = 0;
            }
        }

        // fill all other rows
        for (int i = 1; i < n; ++i) {
            const item& current_item = items[i];

            for (int j = 0; j <= knapsack_size; ++j) {
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
        int i = n - 1;
        int j = knapsack_size;
        int max_value = optimal(i, knapsack_size);

        while (i > 0 && j >= 0) {
            if (optimal(i, j) != optimal(i - 1, j)) {  // requires i > 0
                pos.push_back(i);
                j -= items[i].weight;
            }
            
            i -= 1;
        }

        // check first item, since we couldn't use i == 0 in the previous loop
        if (j >= 0 && optimal(0, j) > 0) {
            pos.push_back(i);
        }

        std::reverse(pos.begin(), pos.end());

        return { max_value, pos };
    }
}
