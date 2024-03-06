// https://codeforces.com/contest/39/problem/J
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;


int main() {
    string s1, s2;
    std::cin >> s1 >> s2;

    int index = -1;

    for (int i = 0, j = 0; i < s1.size(); ++i, ++j) {
        if (j == s2.size()) {
            // handle case when the difference is in the last letter
            index = j;
            break;
        }

        if (s1[i] != s2[j]) {
            if (index == -1) {
                // first different letter
                index = i;
                j -= 1;
            } else {
                // more than one letter differs
                index = -1;
                break;
            }
        }
    }

    if (index != -1) {
        // find the span of the same letter
        char c = s1[index];
        int i;

        for (i = index; i >= 0 && s1[i] == c; --i)
            ;

        int low = i + 1;

        for (i = index + 1; i < s1.size() && s1[i] == c; ++i)
            ;

        int high = i - 1;

        // print results
        cout << high - low + 1 << "\n";
        for (i = low; i <= high; ++i)
            cout << i + 1 << " ";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
