#include <catch2/catch_test_macros.hpp>

// C++17: shorthand declaration of nested namespaces
namespace my::nested::ns {
    int foo() {
        return 42;
    }
}

// namespace alias
namespace myns = my::nested::ns;

TEST_CASE( "Namespaces" ) {
    REQUIRE( my::nested::ns::foo() == 42 );
    REQUIRE( myns::foo() == 42 );  // use the alias
}
