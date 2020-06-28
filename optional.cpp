#include <iostream>
#include <optional>
#include <vector>

std::optional<int> find(const std::vector<int>& v, int n) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == n) {
            return std::optional(static_cast<int>(i));
        }
    }
    return std::nullopt;
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::cout << "found 3 at pos: " << find(nums, 3).value_or(-1) << "\n"; 
    std::cout << "found 4 at pos: " << find(nums, 4).value_or(-1) << "\n"; 
}
