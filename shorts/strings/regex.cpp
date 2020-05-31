#include <iostream>
#include <regex>

int main() {
    std::string input = "Code is ZZ 12345-9999.";

    std::regex re(R"(\w{2}\s*\d{5}(-\d{4})?)");
    std::smatch matches;

    if (std::regex_search(input, matches, re)) {
        std::cout << "Found a match: " << matches[0] << std::endl;
    }
}
