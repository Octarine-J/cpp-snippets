#include <iostream>
#include <tuple>

// can be used to return multiple values from a function
std::tuple<int, std::string> f() {
    return {10, "ten"}; // requires C++17
}

int main() {
    auto t = std::make_tuple(3, "data", true);
    
    // i-th field access 
    std::cout << "Data: " << std::get<1>(t) << std::endl;

    // tie() can be used to deconstruct tuple values (pre-C++17)
    int value;
    std::string spelling;
    std::tie(value, spelling) = f();
    std::cout << "Value: " << value << ", Spelling: " << spelling << std::endl;
    
    // in C++17:
    auto [val, sp] = f();
    std::cout << "Value: " << val << ", Spelling: " << sp << std::endl;

    // tie() is also useful to compare multiple values
    int x = 1, y = 1;
    std::string s1 = "temp", s2 = "test";
    bool cmp = std::tie(x, s1) < std::tie(x, s2);
    std::cout << "Compare result: " << cmp << std::endl;

    auto p = std::make_pair(1, "one");

    // pair haseasier field access than in tuple
    std::cout << "First: " << p.first << ", Second: " << p.second << std::endl;

    return 0;
}
