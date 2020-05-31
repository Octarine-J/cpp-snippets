#include <iostream>
#include <string_view>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

std::vector<std::string_view> tokenize(std::string_view sentence, char separator) {
    std::vector<std::string_view> result;
    size_t pos = 0;

    while (pos != std::string_view::npos) {
        pos = sentence.find(separator);
        result.push_back(sentence.substr(0, pos));

        if (pos != std::string_view::npos) {
            sentence.remove_prefix(pos + 1);
        }
    }

    return result;
}

TEST_CASE( "Tokenize" ) {
    const std::string sentence {"I have a white cat"};
    const std::vector<std::string_view> expected_tokens {"I", "have", "a", "white", "cat"};

    const auto result = tokenize(sentence, ' ');

    REQUIRE( result == expected_tokens );
}
