#include <chrono>
#include <complex>
#include <iostream>
using namespace std::chrono_literals;
using namespace std::complex_literals;
using namespace std::string_literals;

// user defined cooked literal
long double operator"" _in(long double value) {
    return value * 25.4; // mm
}

// user defined raw literal
double operator"" _cm(const char *value) {
    return std::stod(value) * 10; // mm
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "UnusedValue"
int main() {
    // every literal has a type
    unsigned long long i6 = 42ULL;
    float f1 = 1e-3f;
    long double d1 = 3.1415926L;
    long double d2 = 0xa.bcdp-10; // C++17: hex floats

    char c1 = '\7', c2 = '\x4e'; // octal and hexadecimal escape sequences
    char8_t  w1 = u8'\44';        // C++20: utf-8
    char16_t w2 = u'\x394';       // utf-16
    char32_t w3 = U'\u044f';      // utf-32
    wchar_t  w4 = L'\U000000E7';  // also utf-32

    // C++20:  std::u8string, before:  std::string
    // std::u8string is not printable
    std::u8string s1 = u8"日本語"; // utf-8 string (char)

    // string literal that spans multiple lines
    std::cout << "a long long line"
                 " can span multiple lines"
              << std::endl;

    char *p1 = nullptr; // pointer literal

    // standard literals (require using appopriate namespace)
    auto name = "Vasya"s; // string
    auto interval = 40ms; // time, also: min, ns, us, s, h, ...
    auto imag = 1.2i;     // complex

    // using user-defined literals
    std::cout << 1.0_in << std::endl;
    std::cout << 1.0_cm << std::endl;

    return 0;
}
#pragma clang diagnostic pop
