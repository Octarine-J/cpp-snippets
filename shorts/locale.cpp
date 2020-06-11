#include <iostream>
#include <locale>

int main() {
    // without locale
    std::wcout << 65535 << std::endl;

    // using English locale
    std::wcout.imbue(std::locale("en_US"));
    std::wcout << 65535 << std::endl;  // comma separator

    // using Spanish locale
    std::wcout.imbue(std::locale("es_ES"));
    std::wcout << 65535 << std::endl;  // dot separator
}
