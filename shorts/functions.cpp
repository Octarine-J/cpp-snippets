#include <iostream>
#include <string>
#include <vector>

// It is recommended to always use 'references to const'
// when a function does not change its arguments.
bool contains_space(const std::string &s) {
    // __func__ returns current function name
    std::cout << "Executing function '" << __func__ << "'...\n";

    for (const auto &c : s) {
        if (c == ' ') {
            return true;
        }
    }
    return false;
}

// return an object initialized from an initializer list
std::vector<std::string> init_list_example() {
    return {"hello", "world", "!"};
}

// returns lvalue (see in 'main')
std::string &f_ref(std::string &s) {
    return s;
}

// definition using trailing return type
auto my_square(int x) -> int {
    return x * x;
}

// a constexpr function
constexpr int cf() {
    return 42;
}

// functions cannot have array parameters, but they can have
// reference to array parameters
void print_array(const char (&arr)[4]) {
    for (size_t i = 0; i < 3; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// we can use this fact to get the number of elements in the array
template <typename T, size_t N>
constexpr size_t array_size(T (&)[N]) noexcept {
    return N;
} 

int main() {
    std::cout << contains_space("hello world") << std::endl;
    std::cout << init_list_example()[0] << std::endl;
    std::string s;
    f_ref(s) = "hi!"; // can assign to a function result if it is an lvalue
    std::cout << s << std::endl;

    std::cout << "my_square = " << my_square(7) << std::endl;

    constexpr int my_const = cf();
    std::cout << my_const << std::endl;

    const char str[] = "abc";  // const char[4]
    print_array(str);          // cannot call this function if the string above is longer or shorter

    std::cout << "Array Size: " << array_size(str) << std::endl;

    return 0;
}
