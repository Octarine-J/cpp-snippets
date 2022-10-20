#include <iostream>
#include <memory>

#include <catch2/catch_test_macros.hpp>


// passing a smart pointer to a function and returning it
auto print_len(std::shared_ptr<std::string> s) -> decltype(s) {
    std::cout << "length = " << s->length() << "\n";  // dereferencing a smart pointer
    return s;
}

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

TEST_CASE( "Smart Pointers" ) {
    // a unique pointer to int
    // cannot be copied (including passing to a function?)
    auto pi = std::make_unique<double>(3.14);
    REQUIRE( *pi == 3.14 );

    // C++11: a shared pointer to string
    auto ps = std::make_shared<std::string>("test");
    REQUIRE( print_len(ps) == ps );

    // C++17: can use shared_ptr with arrays
    std::shared_ptr<int[]> arr(new int[10] {});
    REQUIRE( arr[9] == 0 );
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

TEST_CASE( "Print Pointer" ) {
    int a = 7;
    int* ptr = &a;

    std::stringstream ss;
    ss << (void*)ptr;

    REQUIRE( ss.str().length() == 16u );
}
