#include <iostream>
#include <cctype>
using std::cout;
using std::endl;

int main() {
    char c = 'a';
    bool isalnum = std::isalnum(c);
    cout << "Is letter or digit: " << std::isalnum(c) << endl;
    cout << "Is letter: " << std::isalpha(c) << endl;
    cout << "Is digit: " << std::isdigit(c) << endl;
    cout << "Is hexadecimal digit: " << std::isxdigit(c) << endl;
    cout << "Is lowercase letter: " << std::islower(c) << endl;
    cout << "Is uppercase letter: " << std::isupper(c) << endl;

    cout << "Is control character: " << std::iscntrl(c) << endl;
    cout << "Is printable and not space: " << std::isgraph(c) << endl;
    cout << "Is printable: " << std::isprint(c) << endl;
    cout << "Is punctuation character: " << std::ispunct(c) << endl;
    cout << "Is whitespace (tab, newline, space, ...): " << std::isspace(c) << endl;

    cout << "To lower case: " << std::tolower(c) << endl;
    cout << "Is upper case: " << std::toupper(c) << endl;

    return 0;
}
