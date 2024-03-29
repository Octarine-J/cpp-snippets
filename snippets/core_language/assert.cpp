#include <cassert>
#include <iostream>

#include <catch2/catch_test_macros.hpp>

int count_words() {
    return 1;
}

TEST_CASE( "Assert" ) {
    // static_assert is evaluated at compile time
    static_assert(sizeof(int) >= 4, "int is too small");

    int words = count_words();

#ifndef NDEBUG
    std::cout << "[DEBUG] We are in function '" << __func__ << "' at file '" << __FILE__
              << "', line " << __LINE__ << "." << std::endl;

    assert(words > 0);
#endif
}
