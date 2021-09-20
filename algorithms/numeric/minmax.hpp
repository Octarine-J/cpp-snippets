#pragma once

#include <functional>
#include <utility>

namespace numerical {

    // Requires: Iterator is a ForwardIterator, Compare is a StrictWeakOrdering
    template<typename Iterator, typename Compare>
    std::pair<Iterator, Iterator> minmax(Iterator begin, Iterator end, Compare compare) {
        if (begin == end) {
            return {end, end};
        }

        Iterator current_min = begin;
        Iterator current_max = begin;

        Iterator current = begin;
        ++current;

        if (current == end) {
            return {current_min, current_max};
        }

        while (current != end) {
            Iterator potential_min = current;
            ++current;

            if (current == end) {
                if (compare(*potential_min, *current_min)) {
                    current_min = potential_min;
                }

                if (compare(*current_max, *potential_min)) {
                    current_max = potential_min;
                }

                break;
            }

            Iterator potential_max = current;

            if (compare(*potential_max, *potential_min)) {
                std::swap(potential_min, potential_max);
            }

            if (compare(*potential_min, *current_min)) {
                current_min = potential_min;
            }

            if (!compare(*potential_max, *current_max)) {
                current_max = potential_max;
            }

            ++current;
        }

        return {current_min, current_max};
    }

    template<typename Iterator>
    std::pair<Iterator, Iterator> minmax(Iterator begin, Iterator end) {
        return numerical::minmax(begin, end, std::less());
    }

}
