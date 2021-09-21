#pragma once

#include <functional>
#include <iterator>

/** 
 * Insertion Sort.
 * Works on vectors, lists.
 * Average: O(n^2), Best: O(n), Worst: O(n^2)
 */
namespace alg::sorting {

    template<std::bidirectional_iterator Iterator, typename Compare>
    void insertion_sort(Iterator begin, Iterator end, Compare compare) {
        if (begin == end) {
            return;
        }

        for (Iterator it = std::next(begin); it != end; ++it) {
            Iterator pos = it;
            auto value = std::move(*it);

            while (compare(value, *(std::prev(pos)))) {
                *pos = std::move(*(std::prev(pos)));
                --pos;

                if (pos == begin) {
                    break;
                }
            }

            *pos = value;
        }
    }

    template<typename Iterator>
    void insertion_sort(Iterator begin, Iterator end) {
        insertion_sort(begin, end, std::less());
    }

}
