#pragma once

#include <functional>
#include <iterator>

/**
 * Bubble Sort.
 * Works on vectors, lists.
 * Average: O(n^2), Best: O(n), Worst: O(n^2).
 */
namespace alg::sorting {

    template<std::bidirectional_iterator Iterator, typename Compare>
    void bubble_sort(Iterator begin, Iterator end, Compare compare) {
        Iterator upper_limit = end;
        bool no_swaps = true;

        for (Iterator i = begin; i != end; ++i) {
            for (Iterator j = std::next(begin); j != upper_limit; ++j) {
                if (compare(*j, *(std::prev(j)))) {
                    std::swap(*j, *(std::prev(j)));
                    no_swaps = false;
                }
            }

            if (no_swaps) {
                break;  // this gives O(n) in the best case
            }

            --upper_limit;
        }
    }

    template<typename Iterator>
    void bubble_sort(Iterator begin, Iterator end) {
        bubble_sort(begin, end, std::less());
    }

}
