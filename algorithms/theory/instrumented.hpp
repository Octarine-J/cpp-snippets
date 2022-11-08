#ifndef INSTRUMENTED_H
#define INSTRUMENTED_H

#include <cstddef>

struct instrumented_base
{
    enum operations {
        n_, copy, default_constructor, destructor, assignment, equality, comparison
    };

    static constexpr size_t number_ops = 7;
    static double counts[number_ops];
    static constexpr char const* counter_names[] {
            "n", "copy", "default", "destruct", "assign", "equal", "less"
    };

    static void initialize(size_t);
};

template <typename T>
struct instrumented : instrumented_base
{
    typedef T value_type;
    T value;

    instrumented(const T& x) : value(x) {}
    
    instrumented(const instrumented& x) : value(x.value) {
        ++counts[copy];
    }

    instrumented() {
        ++counts[default_constructor];
    }

    ~instrumented() {
        ++counts[destructor];
    }

    instrumented& operator=(const instrumented& x) {
        ++counts[assignment];
        value = x.value;
        return *this;
    }
    
    friend bool operator==(const instrumented& x, const instrumented& y) {
        ++counts[equality];
        return x.value == y.value;
    }
    
    friend bool operator!=(const instrumented& x, const instrumented& y) {
        return !(x == y);
    }

    friend bool operator<(const instrumented& x, const instrumented& y) {
        ++counts[comparison];
        return x.value < y.value;
    }

    friend bool operator>(const instrumented& x, const instrumented& y) {
        return y < x;
    }

    friend bool operator<=(const instrumented& x, const instrumented& y) {
        return !(y < x);
    }
    
    friend bool operator>=(const instrumented& x, const instrumented& y) {
        return !(x < y);
    }

};

#endif

