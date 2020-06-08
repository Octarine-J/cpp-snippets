#include <memory>

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

TEST_CASE( "Make Unique Ponter" ) {
    auto i_ptr = std::make_unique<int>(5);

    REQUIRE( *i_ptr == 5 );

    // pass a smart pointer to a function expecting a raw pointer
    auto f = [](int* ptr) -> int {
        return ++(*ptr);
    };

    REQUIRE( f(i_ptr.get()) == 6 );
}

TEST_CASE( "Move Unique Ponter" ) {
    std::unique_ptr<int> i_ptr = std::make_unique<int>(5);
    std::unique_ptr<int> j_ptr = std::move(i_ptr);  // can only move; do not use i_ptr after this

    REQUIRE( *j_ptr == 5 );
}

TEST_CASE( "Smart Pointers with Custom Deleters" ) {
    auto malloc_int = [](int value) -> int* {
        int* ptr = (int*) malloc(sizeof(int));
        *ptr = value;
        return ptr;
    };

    // unique_ptr requires a template argument
    std::unique_ptr<int, decltype(free)*> i_ptr(malloc_int(5), free);

    REQUIRE( *i_ptr == 5 );

    // shared_ptr is easier to declare with a custom deleter
    std::shared_ptr<int> s_ptr(malloc_int(7), free);

    REQUIRE( *s_ptr == 7 );
}

TEST_CASE( "Shared Pointer Aliasing" ) {
    // shared_ptr may be used to share ownership, but point to a different object
    struct Foo {
        int data;
    };

    std::shared_ptr<Foo> ptr1(new Foo {32});
    std::shared_ptr<int> ptr2(ptr1, &ptr1->data); // ptr1 is not destroyed until ptr2 is destroyed

    REQUIRE( *ptr2 == 32 );
}

TEST_CASE( "Weak Pointer" ) {
    // weak_ptr requires shared_ptr to be constructed (or another weak_ptr)
    // it does not free the resource when going out of scope

    auto use_weak_ptr = [](const std::weak_ptr<int>& ptr) -> bool {
        std::shared_ptr<int> s_ptr = ptr.lock();
        return static_cast<bool>(s_ptr);  // true if the resource is available
    };

    std::shared_ptr<int> s_ptr = std::make_shared<int>(42);
    std::weak_ptr<int> w_ptr(s_ptr);

    REQUIRE( use_weak_ptr(w_ptr) );

    s_ptr.reset();

    REQUIRE( !use_weak_ptr(w_ptr) );
}
