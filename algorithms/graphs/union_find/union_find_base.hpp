#ifndef ALGORITHMS_UNION_FIND_BASE_HPP
#define ALGORITHMS_UNION_FIND_BASE_HPP

#include <utility>
#include <vector>

namespace union_find {
    struct UF_Base {
        virtual bool connected(int i, int j) = 0;

        virtual void unite(int i, int j) = 0;

        virtual ~UF_Base() = default;
    };

    template<typename T>
    T construct_UF(size_t n, const std::vector<std::pair<int, int>>& pairs) {
        T u(n);

        for (auto [i, j] : pairs) {
            u.unite(i, j);
        }

        return u;
    }
}

#endif
