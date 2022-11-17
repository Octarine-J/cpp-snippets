#ifndef ALGORITHMS_QUICK_UNION_HPP
#define ALGORITHMS_QUICK_UNION_HPP

#include <utility>
#include <vector>

#include "union_find_base.hpp"

// represent each component as a tree, id[i] is the parent of i
//        0 1 2 3 4 5 6 7 8 9
// id[]  [0 1 9 4 9 6 6 7 8 9]
// here point 4 is the parent of point 3 (id[3] = 4); also 0, 1, 6, 7, 8 are single-node trees
// note that id[9] = 9, but 9 is the root of the biggest tree
//
// two points are in the same component if they have the same root
// to unite two components, change i-th root to be j-th root
//
// we must ensure that trees are balanced;
// when merging two trees, we need to attach smaller tree to a larger one (and not v.v.)

namespace union_find {

    class UF_QuickUnion : UF_Base {
    private:
        std::vector<int> id_;

        struct node_info {
            int root;
            int height;
        };

        // find the root of the tree the point belongs to
        // also find the height of the tree
        node_info root(int i) {
            int height = 0;

            while (id_[i] != i) {
                // path compression: as we're finding the root, we update the parent of each node
                // to point directly to the root; but this will require an extra loop.
                // a compromise: update point's parent to be its grandparent
                id_[i] = id_[id_[i]];

                i = id_[i];
                ++height;
            }

            return {i, height};
        }
    public:
        // O(n)
        explicit UF_QuickUnion(size_t n) : id_(n) {
            // first, assign each point to each own component
            for (size_t i = 0; i < n; ++i) {
                id_[i] = static_cast<int>(i);
            }
        }

        UF_QuickUnion(std::initializer_list<int> id) : id_(id) {}

        // are points in the same component? (= do they have the same root?)
        // O(lg n) - when using weighted trees
        bool connected(int i, int j) override {
            return root(i).root == root(j).root;
        }

        // merge two components: set i-th root (not parent!) to be j-th root
        // changes just one value: much more efficient than QuickFind!
        // O(lg n) - when using weighted trees
        void unite(int i, int j) override {
            auto [root_i, height_i] = root(i);
            auto [root_j, height_j] = root(j);

            // union by height: append smaller tree to a larger
            // another option (not used here) is union by size: rely on tree size (# of nodes) rather than its height
            if (height_i < height_j) {
                id_[root_i] = root_j;
            } else {
                id_[root_j] = root_i;
            }
        }

        const int& operator[](size_t index) const {
            return id_[index];
        }
    };

    // O(n^2) worst case
    UF_QuickUnion quick_union(size_t n, const std::vector<std::pair<int, int>>& pairs) {
        return construct_UF<UF_QuickUnion>(n, pairs);
    }
}

#endif
