#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
struct singleton
{
    T value;

    // semiregular
    
    singleton(const singleton& x) : value(x.value) {}

    singleton() {}

    ~singleton() {}

    singleton& operator=(const singleton& x) {
        value = x.value;
        return *this;
    }

    // regular
    
    friend bool operator==(const singleton& x, const singleton& y) {
        return x.value == y.value;
    }
    
    friend bool operator!=(const singleton& x, const singleton& y) {
        return !(x == y);
    }

    // totally ordered
 
    friend bool operator<(const singleton& x, const singleton& y) {
        return x.value < y.value;
    }

    friend bool operator>(const singleton& x, const singleton& y) {
        return y < x;
    }

    friend bool operator<=(const singleton& x, const singleton& y) {
        return !(y < x);
    }
    
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

