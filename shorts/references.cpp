#include <iostream>

int main() {
    int ival = 17;
    int &rval = ival;  // reference is another name for an object

    rval = 19;  // changes to a reference affect the bound object
    std::cout << "ival = " << ival << std::endl;

    return 0;
}
