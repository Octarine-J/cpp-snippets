#ifndef ALGORITHMS_IN_CPP_LIST_POOL_HPP
#define ALGORITHMS_IN_CPP_LIST_POOL_HPP

#include <cstddef>
#include <vector>

/**
 * A pool of Linked List nodes based on a std::vector.
 */
namespace ds {

    // T: a semiregular type
    // IndexType: an integral type (e.g. uint8_t to save space)
    template<class T, class IndexType = size_t>
    class ListPool {

    private:
        struct Node {
            T value;
            IndexType next;
        };

        std::vector<Node> pool;
        IndexType free_list_head;

        Node& node(IndexType i) {
            return pool[i - 1];
        }

        const Node& node(IndexType i) const {
            return pool[i - 1];
        }

        IndexType create_node() {
            pool.push_back(Node());
            return pool.size();
        }

    public:
        ListPool() {
            free_list_head = empty();
        }

        IndexType empty() const {
            return 0;
        }

        bool is_empty(IndexType i) const {
            return i == empty();
        }

        T& value(IndexType i) {
            return node(i).value;
        }

        const T& value(IndexType i) const {
            return node(i).value;
        }

        // next node in a list
        IndexType& next(IndexType i) {
            return node(i).next;
        }

        const IndexType& next(IndexType i) const {
            return node(i).next;
        }

        IndexType free(IndexType i) {
            IndexType tail = next(i);
            next(i) = free_list_head;
            free_list_head = i;
            return tail;
        }

        IndexType allocate(const T& val, IndexType tail) {
            IndexType i;

            if (is_empty(free_list_head)) {
                i = create_node();
            } else {
                i = free_list_head;
                free_list_head = next(free_list_head);
            }

            value(i) = val;
            next(i) = tail;
            return i;
        }

    };


    template <class T, class IndexType = size_t>
    void free_list(ListPool<T, IndexType>& pool, IndexType i) {
        while (!pool.is_empty(i)) {
            i = pool.free(i);
        }
    }
}



#endif //ALGORITHMS_IN_CPP_LIST_POOL_HPP
