#pragma once

#include <vector>

/**
 * This can be viewed as a device modeling a tennis tournament.
 * [.|.|.|.|...|.]
 * The item in the 0th cell will be a guy who won 0 games,
 * in 1th cell - a guy who won 1 game,
 * in 2nd cell - a guy who won 2 games,
 * etc.
 * The guys that are paired (combined) are always of the
 * same strength (won the same number of games).
 * The winner will be in the last non-empty cell.
 *
 * The size of the binary counter is O(log(N)), where
 * N is the size of the input.
 *
 * This device is useful for problems like to "find the minimum
 * and the second minimum using the least possible number of
 * comparisons".
 */
namespace ds {

    // Op is a binary operation on T
    // Op is associative (needed, because we change the order of combining from linear to tree-like)
    // Iterator is a ForwardIterator
    template<typename T, typename Iterator, typename Op>
    T add_to_counter(Iterator first, Iterator last, Op op, const T& zero, const T& value) {
        T carry = value;

        // counter: [t|t|t| | | | ]
        while (first != last) {
            // case 1: iterator points to an empty slot
            if (*first == zero) {
                *first = carry;
                return zero;
            }

            // case 2: iterator points to some non-zero value
            carry = op(*first, carry);  // combine using Op
            *first = zero;
            ++first;
        }

        return carry;
    }


    // Op is an associative binary operation on T
    // Iterator is a ForwardIterator
    template<typename T, typename Iterator, typename Op>
    T reduce_counter(Iterator first, Iterator last, Op op, const T& zero) {
        // skip leading zeroes in counter
        while (first != last && *first == zero) {
            ++first;
        }

        if (first == last) {
            return zero;  // counter was empty
        }

        T result = *first;  // first non-zero element in the counter

        // combine all non-zero elements in the counter
        while (++first != last) {
            if (*first != zero) {
                result = op(*first, result);  // order is important, Op is not commutative
            }
        }

        return result;
    }


    template<typename T, typename Op>
    class binary_counter {
    private:
        std::vector<T> counter;
        T zero;
        Op op;
    public:
        binary_counter(const Op& op, const T& zero) : op(op), zero(zero) {
            counter.reserve(24);
        }

        void add(const T& value) {
            T result = add_to_counter(counter.begin(), counter.end(), op, zero, value);
            if (result != zero) {
                counter.push_back(result);
            }
        }

        T reduce() {
            return reduce_counter(counter.begin(), counter.end(), op, zero);
        }

        template <class Iterator>
        T apply(Iterator first, Iterator last) {
            while (first != last) {
                add(first++);
            }

            return reduce();
        }
    };

    template <class T, class Iterator, class Op>
    T apply_counter(Iterator first, Iterator last, const T& zero, Op op) {
        ds::binary_counter counter(op, zero);
        return counter.apply(first, last);
    }

}

