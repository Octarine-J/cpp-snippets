#include <cstddef>
#include <iostream>
#include <limits>

int main() {
    // integral types
    bool a = true;
    char b = 'b'; // 1 byte, uses either 'signed char' or 'unsigned char' representation
    wchar_t c = L'c';
    char16_t d = u'd'; // for Unicode
    char32_t e = U'e'; // same
    std::cout << a << " " << b << std::endl;
    std::wcout << " " << c << std::endl;
    std::cout << d << " " << e << std::endl; // no built-in support to output Unicode

    short f = 32267;
    int g = 32267;                     // at least 16 bits
    long h = 3000000000;               // at least 32 bits
    long long i = 3000000000333000333; // 64 bits
    std::cout << f << " " << g << " " << h << " " << i << std::endl;

    // floating-point types
    float j = 12.350002;           // 6 significant digits
    double k = 7.132030293;        // 10 significant digits
    long double l = 13.0505000088; // also 10 significant digits
    std::cout << j << " " << k << " " << l << std::endl;

    // min and max values are available in <limits>
    float min_float = std::numeric_limits<float>::min();
    float max_float = std::numeric_limits<float>::max();

    // can also check whether char is signed or not on our platform
    bool char_is_signed = std::numeric_limits<char>::is_signed;

    // signed values are automatically promoted to unsigned
    // when both signed and unsigned types are used in the same expression
    // this may yield surprising results!
    int s = -10;
    unsigned int u = 42;
    std::cout << u * s << std::endl; // 4294966876

    // C++17
    std::byte bt{42};

    // sizeof operator outputs the size of a type in bytes
    std::cout << "Size of char32_t: " << sizeof(char32_t) << std::endl;
    std::cout << "Size of double:   " << sizeof(double) << std::endl;

    return 0;
}
