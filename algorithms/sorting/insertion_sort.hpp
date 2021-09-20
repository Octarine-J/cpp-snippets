#pragma once

#include <functional>

namespace sorting {

    template<typename Iterator, typename Compare>
    void insertion_sort(Iterator begin, Iterator end, Compare compare) {
        if (begin == end) {
            return;
        }

        for (auto it = begin + 1; it != end; ++it) {
            auto pos = it;
            auto value = std::move(*it);

            while (compare(value, *(pos - 1))) {
                *pos = std::move(*(pos - 1));
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
