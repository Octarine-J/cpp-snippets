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
    const std::string sentence = "I have a white cat";
    const std::vector<std::string_view> expected_tokens {"I", "have", "a", "white", "cat"};

    const auto tokens = tokenize(sentence, ' ');

    REQUIRE( tokens == expected_tokens );
}

// DO NOT use string_view for temporary objects, e.g.
// string s = "test";
// string_view sw { s + " app" };
// cout << sw;  // undefined behavior

// Another example: work with string_view
// but return string when needed
std::string get_extension(std::string_view filename) {
    std::size_t pos = filename.rfind('.');
    if (pos != std::string::npos) {
        return std::string {filename.substr(pos + 1)};
    } else {
        return {};
    }
}

TEST_CASE( "String View: Get Extension" ) {
    REQUIRE( get_extension("C:\\data\\file.docx") == "docx" );
    REQUIRE( get_extension("file.dat") == "dat" );
    REQUIRE( get_extension("file") == "" );
}
