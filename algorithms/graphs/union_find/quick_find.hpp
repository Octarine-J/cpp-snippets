#ifndef ALGORITHMS_QUICK_FIND_HPP
#define ALGORITHMS_QUICK_FIND_HPP

#include <utility>
#include <vector>

#include "union_find_base.hpp"

// simplest structure
// points i and j are connected, if they have the same id, i.e. id[i] = id[j]
//        0 1 2 3 4 5 6 7 8 9
// id[]  [0 1 1 8 8 0 0 1 8 8]
// here 0, 5, and 6 are connected; 1, 2, and 7 are connected; and 3, 4, 8, and 9 are connected

namespace union_find {

    // structure that supports the algorithm
    class UF_QuickFind : UF_Base {
        std::vector<int> id_;
    public:
        // O(n)
        explicit UF_QuickFind(size_t n) : id_(n) {
            // first, assign each point to each own component
            for (size_t i = 0; i < n; ++i) {
                id_[i] = static_cast<int>(i);
            }
        }

        UF_QuickFind(std::initializer_list<int> id) : id_(id) {}

        // are points in the same component?
        // O(1)
        bool connected(int i, int j) override {
            return id_[i] == id_[j];
        }

        // merge two components
        // O(n)
        void unite(int i, int j) override {
            int current_id = id_[i];
            int target_id = id_[j];

            for (auto& entry: id_) {
                if (entry == current_id) {
                    entry = target_id;
                }
            }
        }

        const int& operator[](size_t index) const {
            return id_[index];
        }
    };

    // the algorithm itself
    // O(n^2)
    UF_QuickFind quick_find(size_t n, const std::vector<std::pair<int, int>>& pairs) {
        return construct_UF<UF_QuickFind>(n, pairs);
    }
}

#endif
