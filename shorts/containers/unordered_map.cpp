#include <functional>
#include <iostream>
#include <map>
#include <string>

/**
 * unordered_map is implemented using hashes; lookup: O(1)
 * need to implement operator== and a hash function when using custom keys
 */

class IntBox {
    int value;
public:
    explicit IntBox(int value) : value(value) {}

    int get_value() const {
        return value;
    }

    friend bool operator==(const IntBox&, const IntBox&);
};

bool operator==(const IntBox& x, const IntBox& y) {
    return x.value == y.value;
}

// hash template specialization must be added to std::
namespace std {
    template<>
    struct hash<IntBox> {
        using argument_type = IntBox;
        using result_type = size_t;

        result_type operator()(const argument_type& f) const {
            return std::hash<int>()(f.get_value());
        }
    };
}

int main() {
    std::unordered_map<IntBox, std::string> numbers = {
        {IntBox(1), "one"},
        {IntBox(2), "two"}
    };

    std::cout << "Map has key IntBox(2): " << numbers.count(IntBox(2)) << "\n"
        << "Bucket Count: " << numbers.bucket_count() << "\n"
        << "Load Factor: " << numbers.load_factor() << "\n";
}
