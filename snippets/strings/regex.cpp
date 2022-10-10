#include <iostream>
#include <regex>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Search in a substring" ) {
    std::string input = "Code is ZZ 12345-9999.";

    std::regex re {R"(\w{2}\s*\d{5}(-\d{4})?)"};
    std::smatch matches;

    bool found_match = std::regex_search(input, matches, re);

    REQUIRE( found_match );
    REQUIRE( matches[0] == "ZZ 12345-9999" );
}

TEST_CASE( "Regex without creating a group" ) {
    std::regex re {"ab(?:c|d)"};

    REQUIRE( std::regex_match("abc", re) );
    REQUIRE( std::regex_match("abd", re) );
    REQUIRE( ! std::regex_match("abe", re) );
}

TEST_CASE( "Match digits" ) {
    // digits
    std::regex re {R"(\d+)"};

    REQUIRE( std::regex_match("123", re) );
    REQUIRE( std::regex_match("7", re) );
    REQUIRE( ! std::regex_match("a", re) );
    REQUIRE( ! std::regex_match("", re) );

    // not digits
    re = std::regex {R"(\D+)"};

    REQUIRE( std::regex_match("abc", re) );
    REQUIRE( std::regex_match(" ", re) );
    REQUIRE( ! std::regex_match("123", re) );
}

TEST_CASE( "Match alphanumeric characters" ) {
    // alnum
    std::regex re {R"(\w+)"};

    REQUIRE( std::regex_match("123", re) );
    REQUIRE( std::regex_match("abc7", re) );
    REQUIRE( ! std::regex_match("abc abc", re) );

    // not alnum
    re = std::regex(R"(\W+)");
    REQUIRE( std::regex_match(" \t '", re) );
    REQUIRE( ! std::regex_match("abc7", re) );
}

TEST_CASE( "Match space" ) {
    // space
    std::regex re {R"(\s+)"};

    REQUIRE( std::regex_match(" ", re) );
    REQUIRE( std::regex_match("\t", re) );
    REQUIRE( std::regex_match("\t\n\n", re) );

    // not space
    re = std::regex(R"(\S+)");
    REQUIRE( std::regex_match("av's", re) );
    REQUIRE( ! std::regex_match("ab cd", re) );
}

TEST_CASE( "Back references" ) {
    // 4 digits followed by a dash, then the same 4 digits
    std::regex re {R"((\d{4})-\1)"};

    REQUIRE( std::regex_match("1234-1234", re) );
    REQUIRE( std::regex_match("9822-9822", re) );
    REQUIRE( ! std::regex_match("9822-9823", re) );
}

TEST_CASE( "Match groups" ) {
    std::regex re {R"((\d{3})-(\d{4}))"};

    std::cmatch match;
    bool found = std::regex_match("127-0001", match, re);

    REQUIRE( found );
    REQUIRE( match[0] == "127-0001");
    REQUIRE( match[1] == "127");
    REQUIRE( match[2] == "0001");
}

TEST_CASE( "Iterate over pattern occurrences in a string" ) {
    std::regex re {R"(\w+)"};

    std::string input = "this is a white cat";
    std::vector<std::string> result;

    const std::sregex_token_iterator end;
    for (std::sregex_token_iterator it(input.begin(), input.end(), re); it != end; ++it) {
        result.push_back( *it );
    }

    REQUIRE( result == std::vector<std::string>{"this", "is", "a", "white", "cat"} );
}

TEST_CASE( "Tokenization using a regex" ) {
    std::regex re {R"(\s*,\s*)"};

    std::string input = " some , comma,separated, values ,!,x ";
    std::vector<std::string> result;

    // -1: tokens that DO NOT match the regex
    const std::sregex_token_iterator end;
    for (std::sregex_token_iterator it(input.begin(), input.end(), re, -1); it != end; ++it) {
        result.push_back( *it );
    }

    // NOTE: the space before the first word and after the last word is not removed
    REQUIRE( result == std::vector<std::string>{" some", "comma", "separated", "values", "!", "x "} );
}

TEST_CASE( "Replace" ) {
    std::regex re {R"(<h1>(.*)</h1><p>(.*)</p>)"};
    std::string input = "<body><h1>Header</h1><p>Paragraph</p></body>";
    const std::string format = "<h2>$1<br>$2</h2>";

    std::string result = std::regex_replace(input, re, format);

    REQUIRE( result == "<body><h2>Header<br>Paragraph</h2></body>");
}

TEST_CASE( "Replace discarding the parts that do not match regex" ) {
    std::regex re {R"(<h1>(.*)</h1><p>(.*)</p>)"};
    std::string input = "<body><h1>Header</h1><p>Paragraph</p></body>";
    const std::string format = "<h2>$1<br>$2</h2>";

    std::string result = std::regex_replace(input, re, format,
                                            std::regex_constants::format_no_copy);

    REQUIRE( result == "<h2>Header<br>Paragraph</h2>");
}
