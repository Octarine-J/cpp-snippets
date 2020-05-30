#include <iostream>
#include <vector>
//#include <iterator>
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> v1;      // an empty vector
    vector<int> v2(v1);  // v2 holds a copy of each element of v1

    vector<int> v3(10, 0);  // initializes v3 with ten zeroes

    // a vector of size 10, elements are value-initialized:
    // built-in types get zero; class objects are created by the default constructor
    vector<int> v4(10);

    vector<int> u{1, 3, 4, 5, 9};  // init a vector with specified values
    u.push_back(11);               // add an element to the vector

    // init a vector from an array
    int arr[] = {1, 2, 7, 9, 13};
    vector<int> v5(std::begin(arr), std::end(arr));
    // partial copy of an array
    vector<int> v6(arr + 1, arr + 3);  // elements 1 and 2

    // change each element in a vector
    for (auto &elem : u) {
        elem *= 2;
    }

    // print each element in a vector
    cout << "[ ";
    for (auto elem : u) {
        cout << elem << " ";
    }
    cout << "]" << endl;

    cout << "is empty: " << u.empty() << endl;
    cout << "size = " << u.size() << endl;
    cout << "first element: " << u[0] << endl;

    // vector comparison
    vector<int> x{7, 14};
    vector<int> y{7, 14};
    vector<int> z{14, 7};

    cout << "x == y: " << (x == y) << endl;
    cout << "x == z: " << (x == z) << endl;
    cout << "x < z:  " << (x < z) << endl;

    return 0;
}
