#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

TEST_CASE( "Reference to a Ponter" ) {
    int* ptr = nullptr;

    // reference to a pointer can be used to modify the passed pointer
    auto alloc = [](int*& p) {
        p = new int[10];
    };

    alloc(ptr);

    REQUIRE( ptr != nullptr );
    delete[] ptr;
}
