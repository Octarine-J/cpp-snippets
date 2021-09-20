#pragma once

#include <functional>

namespace sorting {

    template<typename Iterator, typename Compare>
    void bubble_sort(Iterator begin, Iterator end, Compare compare) {
        for (auto i = begin; i != end; ++i) {
            for (auto j = begin + 1; j != end - (i - begin); ++j) {
                if (compare(*j, *(j - 1))) {
                    std::swap(*j, *(j - 1));
                }
            }
        }
    }

    template<typename Iterator>
    void bubble_sort(Iterator begin, Iterator end) {
        bubble_sort(begin, end, std::less());
    }

}
