#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
struct singleton
{
    T value;

    // semiregular type (1-4):
    
    // 1. copy constructor; must accept by a const ref (otherwise: non-ending recursion)
    singleton(const singleton& x) : value(x.value) {}

    // 2. default constructor
    singleton() {}

    // 3. destructor
    ~singleton() {}

    // 4. assignment operator
    singleton& operator=(const singleton& x) {
        value = x.value;
        return *this;
    }

    // regular type (5-6):
    
    // 5. equality
    // note that this is NOT a member function
    friend bool operator==(const singleton& x, const singleton& y) {
        return x.value == y.value;
    }
    
    // 6. inequality
    friend bool operator!=(const singleton& x, const singleton& y) {
        return !(x == y);
    }

    // totally ordered type (7-10):
 
    // 7. less then
    // all other comparisons are defined by using this operator
    friend bool operator<(const singleton& x, const singleton& y) {
        return x.value < y.value;
    }

    // 8.
    friend bool operator>(const singleton& x, const singleton& y) {
        return y < x;
    }

    // 9.
    friend bool operator<=(const singleton& x, const singleton& y) {
        return !(y < x);
    }
    
    // 10.
    friend bool operator>=(const singleton& x, const singleton& y) {
        return !(x < y);
    }

    // conversions from T and to T
    
    typedef T value_type;

    explicit singleton(const T& x) : value(x) {}

    explicit operator T() const {
        return value;
    }

    // allow conversions such as between singleton<int> and singleton<double>
    
    template <typename U>
    singleton(const singleton<U>& x) : value(x.value) {}
};

#endif

