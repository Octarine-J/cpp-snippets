#include "binary_counter.hpp"

#include <catch2/catch_test_macros.hpp>


template <typename Iterator, typename Compare>
Iterator min_element_binary(Iterator first, Iterator last, Compare compare) {
    auto min_op = [compare](Iterator x, Iterator y) -> Iterator {
        return compare(*y, *x) ? y : x;
    };

    ds::binary_counter counter(min_op, last);  // use last as zero
    return counter.apply(first, last);
}

TEST_CASE( "Binary Counter Test" ) {
    int data[] = {9, 13, 7, 124, 32, 17, 8, 32, 237, 417, 41, 42, 13, 14, 15};

    auto result = min_element_binary(std::begin(data), std::end(data), std::less());

    REQUIRE( *result == 7 );
}
