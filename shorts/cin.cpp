#include <iostream>
#include <string>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Input numbers to add (CTRL+Z on Windows / CTRL+D on UNIX to stop.)" << endl;

    if (!cin.good()) {
        cerr << "Error: cin is in a bad state." << endl;
        return 1;
    }

    int sum = 0;
    int number;

    while (!cin.bad()) {
        cin >> number;

        if (cin.eof()) {
            break;
        }

        if (cin.fail()) {
            cin.clear();  // reset error state

            std::string bad_token;
            cin >> bad_token;
            cerr << "Warning: bad token '" << bad_token << "'" << endl;

            continue;
        }

        sum += number;
    }

    cout << "sum = " << sum << endl;
}