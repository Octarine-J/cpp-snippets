#include <catch2/catch_test_macros.hpp>

// C++17: shorthand declaration of nested namespaces
namespace my::nested::ns {
    int foo() {
        return 42;
    }
}

namespace foo_ns {
    // everything in inline namespace is available in all parent namespaces
    inline namespace bar_ns {
        int inc(int x) {
            return x + 1;
        }
    }
}

// namespace alias
namespace myns = my::nested::ns;

TEST_CASE( "Namespaces" ) {
    REQUIRE( my::nested::ns::foo() == 42 );
    REQUIRE( myns::foo() == 42 );  // use the alias

    using namespace foo_ns;
    REQUIRE( foo_ns::inc(4) == 5 );  // can call inc() in inline namespace
}
