#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
decltype(auto) sum(vector<T> v, T acc = 0) {  // automatically deduce return type and preserve constness
    for (T &e : v) {
        acc = acc + e;
    }
    return acc;
}

// variadic template (base case, must be declared first)
template <typename T>
void print_all(T value) {
    std::cout << value << std::endl;
}

// variadic template (list of values of different types)
template <typename T, typename... Rest>
void print_all(T head, Rest... tail) {  // function must have the same name
    std::cout << head << " ";
    print_all(tail...);  // recursive call
}

// C++14: variable template
template <typename T>
const T pi = T(3.1415926);


int main() {
    vector<double> a = {1.23, 3.14, 7.23, 9.92};
    cout << "sum(a) = " << sum(a) << endl;

    vector<int> b = {1, 2, 3};
    cout << "sum(b) = " << sum(b) << endl;

    vector<string> c = {"Hello", ", ", "world", "!"};
    cout << "sum(c) = " << sum(c, string()) << endl;

    print_all(3.0, 22, "bread", true);

    float floatPi = pi<float>;
    double doublePi = pi<double>;
}
