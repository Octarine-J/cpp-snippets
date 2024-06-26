#include <memory>
#include <sstream>

#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Pointers" ) {
    // declaring a pointer
    int a = 10;
    int* pa = &a;
    int*& ref = pa;  // a reference to a pointer

    *ref = 20;
    REQUIRE( a == 20 );

    // a void* pointer can point to any type
    void* pv = &a;
    REQUIRE( *static_cast<int*>(pv) == 20 );
}

TEST_CASE( "Delete Pointer" ) {
    // can safely delete a nullptr pointer
    int* ptr = nullptr;
    delete ptr;

    REQUIRE( ptr == nullptr );
}

TEST_CASE( "Modify Pointer Passed to Function" ) {
    int* ptr = nullptr;

    // reference to a pointer can be used to modify the passed pointer
    auto alloc = [](int*& p) {
        p = new int[10];
    };

    alloc(ptr);
    REQUIRE( ptr != nullptr );

    delete ptr;
}

TEST_CASE( "New and Malloc Differences" ) {
    // malloc: doesn't call constructors; returns null when allocation failed
    // new: calls constructors, throws bad_alloc exception if allocation failed

    // can force new to return nullptr instead of throwing an exception:
    int* ptr = new(std::nothrow) int[5];

    REQUIRE( ptr != nullptr );

    // delete: unlike free() calls objects' destructors
    delete[] ptr;
}

TEST_CASE( "Print Pointer" ) {
    int a = 7;
    int* ptr = &a;

    std::stringstream ss;
    ss << (void*)ptr;

    std::string address = ss.str();
    REQUIRE( (address.length() == 16u || address.find("0x") != std::string::npos) );
}
