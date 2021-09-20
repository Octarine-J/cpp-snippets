#pragma once

#include <functional>
#include <iterator>

namespace alg {

    // It is a RandomAccessIterator
    // NOTE: this template uses C++20 concepts
    template<std::random_access_iterator It, typename Compare, typename T>
    It binary_search(T target, It begin, It end, Compare compare) {
        size_t low = 0;
        size_t high = end - begin;

        while (low < high) {
            size_t mid = low + (high - low) / 2;
            T& mid_item = begin[mid];  // only for RandomAccessIterator

            if (compare(mid_item, target)) {
                return begin + mid;
            } else if (target < mid_item) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return end;  // not found
    }

    template<std::random_access_iterator It, typename T>
    It binary_search(T target, It begin, It end) {
        return binary_search(target, begin, end, std::equal_to());
    }

}
