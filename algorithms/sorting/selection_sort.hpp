#pragma once

#include <functional>
#include <iterator>

/**
 * Selection Sort.
 * Works on vectors, lists.
 * Average: O(n^2), Best: O(n^2), Worst: O(n^2).
 */
namespace alg::sorting {

    template<std::bidirectional_iterator Iterator, typename Compare>
    void selection_sort(Iterator begin, Iterator end, Compare compare) {
        for (Iterator current = begin; current != end; ++current) {
            Iterator min = current;

            for (Iterator it = std::next(current); it != end; ++it) {
                if (compare(*it, *min)) {
                    min = it;
                }
            }

            std::swap(*current, *min);
        }
    }

    template<std::bidirectional_iterator Iterator>
    void selection_sort(Iterator begin, Iterator end) {
        return selection_sort(begin, end, std::less());
    }
}
