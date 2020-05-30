#ifndef INSTRUMENTED_H
#define INSTRUMENTED_H

#include <cstddef>

struct instrumented_base
{
    enum operations {
        n_, copy, default_constructor, destructor, assignment, equality, comparison
    };

    static const size_t number_ops = 7;
    static double counts[number_ops];
    static const char* counter_names[number_ops];

    static void initialize(size_t);
};

template <typename T>
struct instrumented : instrumented_base
{
    typedef T value_type;
    T value;

    explicit instrumented(const T& x) : value(x) {}
    
    // semiregular
    
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

    // regular
    
    friend bool operator==(const instrumented& x, const instrumented& y) {
        ++counts[equality];
        return x.value == y.value;
    }
    
    friend bool operator!=(const instrumented& x, const instrumented& y) {
        return !(x == y);
    }

    // totally ordered
 
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

