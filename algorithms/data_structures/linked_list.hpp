#pragma once

#include <initializer_list>
#include <stdexcept>
#include <string>

/**
 * Singly Linked List:
 * - add_first: O(1)
 * - add_last: O(1)
 * - top: O(1)
 * - remove_first: O(1)
 * - size: O(1)
 * - node_at: O(n)
 * The list can also be used as a stack.
 *
 * The list includes the last sentinel to provide the end() iterator.
 */
namespace ds {

    template <class T>
    class LinkedList {

    private:
        struct Node {
            T value;
            Node* next = nullptr;
        };

        Node* first;
        Node* after_last;
        size_t count;

        // O(n)
        Node* node_at(size_t i) {
            if (i >= count) {
                throw std::invalid_argument(std::string("index out of bounds: ") + std::to_string(i));
            }

            Node* p = first;

            while (i-- != 0) {
                p = p->next;
            }

            return p;
        }

    public:
        LinkedList() {
            after_last = new Node;
            first = after_last;
            count = 0;
        }

        LinkedList(std::initializer_list<T> values) : LinkedList() {
            for (auto it = std::rbegin(values); it != std::rend(values); ++it) {
                add_first(*it);
            }
        }

        // O(1)
        // Adds an item to the head of the list.
        void add_first(T value) {
            Node* p = new Node();
            p->value = value;
            p->next = first;
            first = p;
            ++count;
        }

        // O(1)
        // Adds an item to the end of the list.
        void add_last(T value) {
            after_last->value = value;
            after_last->next = new Node();
            after_last = after_last->next;
            ++count;
        }

        T& top() {
            if (count == 0) {
                throw std::invalid_argument("the list is empty");
            }

            return first->value;
        }

        void remove_first() {
            if (count == 0) {
                throw std::invalid_argument("the list is empty");
            }

            Node* p = first;
            first = first->next;
            delete p;
            --count;
        }

        // O(n)
        void reverse() {
            if (count <= 1) {
                return;
            }

            Node* p_prev = nullptr;
            Node* p_current = first;
            Node* p_next;

            while (p_current != after_last) {
                p_next = p_current->next;
                p_current->next = p_prev;
                p_prev = p_current;
                p_current = p_next;
            }

            first->next = after_last;
            first = p_prev;
        }

        // O(n)
        T& operator[](size_t i) {
            Node* p = node_at(i);
            return p->value;
        }

        // O(1)
        size_t size() {
            return count;
        }

        ~LinkedList() {
            Node* p = first;
            Node* d;

            while (p != nullptr) {
                d = p;
                p = p->next;
                delete d;
            }
        }

        class Iterator {
        private:
            Node* ptr;
        public:
            explicit Iterator(Node* ptr) : ptr(ptr) {}

            Iterator& operator++() {
                ptr = ptr->next;
                return *this;
            }

            bool operator==(const Iterator& other) {
                return this->ptr == other.ptr;
            }

            bool operator!=(const Iterator& other) {
                return this->ptr != other.ptr;
            }

            const T& operator*() {
                return ptr->value;
            }
        };

        Iterator begin() {
            return Iterator(first);
        }

        Iterator end() {
            return Iterator(after_last);
        }

    };

}
