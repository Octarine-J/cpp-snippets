#include <array>
#include <cstring>
#include <iostream>
#include <iterator>

int main() {
    constexpr auto MSG_SIZE = 24;
    char *msg = new char[MSG_SIZE];
    // clearing the contents
    std::memset(msg, 0, MSG_SIZE);

    int arr[10];        // an array of size ten, contents are undefined
    int(*p)[10] = &arr; // a pointer to an array of size 10
    int(&a)[10] = arr;  // a reference to an array of size 10

    // array iterators (using <iterator> header):
    for (int *it = std::begin(arr); it != std::end(arr); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // sizeof operator returns the size of the entire array
    std::cout << "Size of arr: " << sizeof arr << "\n";
    // C++17: number of elements in the array
    std::cout << "Number of elements in arr: " << std::size(arr) << "\n";

    // a modern way to create an array
    std::array<double, 3> values = {1.0, 1.5, 2.0};
    std::cout << "Number of elements in 'values': " << values.size() << "\n";
    // arrays created in such way can be compared
    std::array<double, 3> values_copy = {1.0, 1.5, 2.0};
    std::cout << "values == values_copy: " << std::boolalpha << (values == values_copy) << "\n";

    // array zero init
    std::array<double, 3> zeroes = {};

    // C++17: structured bindings for arrays
    std::array<int, 3> nums = {100, 200, 300};
    auto [n1, n2, n3] = nums;
    std::cout << n3 << std::endl;

    // a two-dimensional array
    int z[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}};
    // need to use references to iterate over such an array
    // (except the most inner loop):
    std::cout << "Two-dimensional array:\n";
    for (const auto &row : z) {
        for (auto col : row) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
