#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main() {
    string s(10, 'c');         // cccccccccc
    string s2("hello, " + s);  // direct initialization
    cout << s2 << endl;
    string sc = "some string";  // copy initialization
    cout << sc << endl;

    string s3;  // empty string
    cout << "Input: ";
    getline(std::cin, s3);  // get entire line including spaces
    cout << "Your input is: " << s3 << endl;

    cout << "Is empty: " << s3.empty() << endl;

    auto s3_size = s3.size();  // the type is std::string::size_type
    cout << "Size: " << s3_size << endl;

    if (!s3.empty()) {
        cout << "First character is: " << s3[0] << endl;
    }

    if (s3 == "test") {
        cout << "Equals 'test'!" << endl;
    }

    if (s3 < "test") {
        cout << "Less then 'test'" << endl;
    }

    // converting string to double
    double d = std::stod("12.987");
    cout << "d = " << d << endl;

    // double to string
    string ds = std::to_string(d);

    // do something with every char in a string
    for (auto c : s3) {  // c is a copy
        cout << c << " ";
    }
    cout << endl;

    // change the string character by character
    for (auto &c : s3) {  // c is a reference to a character in s3
        c = toupper(c);
    }
    cout << "String is now: " << s3 << endl;

    return 0;
}
