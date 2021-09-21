#pragma once

#include <functional>
#include <iterator>

/**
 * Quick Sort.
 * Works with vectors, lists.
 * Average: O(n log(n)), Best: O(n log(n)), Worst: O(n^2)
 */
namespace alg::sorting {

    // in-place, recursive
    template<std::forward_iterator Iterator, typename Compare>
    void quick_sort(Iterator begin, Iterator end, Compare compare) {
        if (begin == end || std::next(begin) == end) {
            return;
        }

        Iterator pivot = begin;  // TODO: better pivot choice
        auto pivot_value = *pivot;

        for (Iterator it = std::next(begin); it != end; ++it) {
            if (compare(*it, pivot_value)) {
                *pivot = *it;
                
                ++pivot;
                *it = *pivot;
            }
        }

        *pivot = pivot_value;

        quick_sort(begin, pivot, compare);
        quick_sort(std::next(pivot), end, compare);
    }

    template<std::forward_iterator Iterator>
    void quick_sort(Iterator begin, Iterator end) {
        return quick_sort(begin, end, std::less());
    }
}
