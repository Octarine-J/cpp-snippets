#include <iostream>
#include <string_view>

std::string longest_palindrome(std::string_view s) {
    std::string longest;

    for (int i = 0, n = static_cast<int>(s.size()); i < n; ++i) {
        int st = i, ed = i;
        bool extend = true;

        char c = s[i];
        bool same_char = true;

        while (extend) {
            extend = false;

            // can extend to both right and left chars
            if (st - 1 >= 0 && ed + 1 < n) {
                if (s[st - 1] == s[ed + 1]) {
                    same_char = same_char && s[st - 1] == c && s[ed + 1] == c;
                    st -= 1;
                    ed += 1;
                    extend = true;
                }
            }

            if (!extend && same_char && st - 1 >= 0) {
                if (s[st - 1] == c) {
                    st -= 1;
                    extend = true;
                }
            }

            if (!extend && same_char && ed + 1 < n) {
                if (s[ed + 1] == c) {
                    ed += 1;
                    extend = true;
                }
            }
        }

        int len = ed - st + 1;
        if (len > longest.size()) {
            longest = s.substr(st, len);
        }
    }

    return longest;
}

void ans(std::string_view s) {
    std::cout << longest_palindrome(s) << "\n";
}

int main() {
    ans("babad");
    ans("cbbd");
}
