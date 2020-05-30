#include <iostream>
#include <string>

bool binary_search(std::string s, char c) {
    auto beg = s.begin(), end = s.end();  // end points one position past the last element
    auto mid = beg + (end - beg) / 2;
    while (mid != end && *mid != c) {
        if (c < *mid) {
            end = mid;
        } else {
            beg = mid + 1;
        }
        mid = beg + (end - beg) / 2;
    }
    return mid != end && (*mid) == c;
}

int main() {
    std::string s = "a sample sentence";
    for (auto it = s.begin(); it != s.end(); ++it) {
        (*it) = toupper(*it);
    }

    // a const iterator
    for (auto it = s.cbegin(); it != s.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // get the middle element
    auto mid = s.begin() + s.size() / 2;
    std::cout << "Middle element: '" << *mid << "'" << "\n";

    std::string test = "abcdgklmnpruz";
    std::cout << "Found 'p': " << binary_search(test, 'p') << "\n";
    std::cout << "Found 'x': " << binary_search(test, 'x') << "\n";
}
