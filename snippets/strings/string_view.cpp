#include <string_view>
#include <vector>

#include <catch2/catch_test_macros.hpp>


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

// do NOT use string_view for temporary objects, e.g.
// string s {"test"};
// string_view sw { s + " app" };
// cout << sw;  // undefined behavior
