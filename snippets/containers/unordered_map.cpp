#include <functional>
#include <map>
#include <string>

#include <catch2/catch_test_macros.hpp>


// unordered_map is implemented using hashes, lookup complexity is O(1).
// Need to implement operator== and a hash function when using custom keys.

// suppose we use this class as a key in unordered_map
class IntBox {
    int value;
public:
    explicit IntBox(int value) : value(value) {}

    [[nodiscard]]
    int get_value() const {
        return value;
    }

    friend bool operator==(const IntBox&, const IntBox&);
};

bool operator==(const IntBox& x, const IntBox& y) {
    return x.value == y.value;
}

// then a hash template specialization must be added to std::
namespace std {
    template<>
    struct hash<IntBox> {
        using argument_type = IntBox;
        using result_type = size_t;

        result_type operator()(const argument_type& x) const {
            return std::hash<int>()(x.get_value());
        }
    };
}

TEST_CASE( "Unordered (hash) map with custom keys" ) {
    std::unordered_map<IntBox, std::string> numbers {
            {IntBox(1), "one"},
            {IntBox(2), "two"}
    };

    REQUIRE( numbers.count(IntBox(2)) == 1 );
    REQUIRE( numbers.bucket_count() > 2 );
    REQUIRE( numbers.load_factor() < 0.8 );
}
