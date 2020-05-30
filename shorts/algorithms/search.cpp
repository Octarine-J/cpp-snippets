#include <algorithm>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"


TEST_CASE( "Search in a Container" ) {
    std::vector<std::string> words = {"archive", "business", "book"};

    // find words starting with b;
    auto result = std::find_if(words.begin(), words.end(), [](auto& word) {
        return word[0] == 'b';
    });

    REQUIRE( *result == "business" );  // first result

    ++result;
    REQUIRE( *result == "book" );  // second result
}
