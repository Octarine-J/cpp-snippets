#include <iostream>
#include <string_view>
#include <vector>

std::vector<std::string_view> tokenize(const std::string &sentence, char separator) {
    std::vector<std::string_view> result;

    size_t pos = 0;
    std::string_view sv{sentence};

    while (pos != sv.npos) {
        pos = sv.find(separator);
        result.push_back(sv.substr(0, pos));

        if (pos != sv.npos) {
            sv.remove_prefix(pos + 1);
        }
    }

    return result;
}

int main() {
    auto tokens = tokenize("I have a white cat", ' ');

    for (const auto &token : tokens) {
        std::cout << token << std::endl;
    }
}
