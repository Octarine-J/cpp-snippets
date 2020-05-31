#include <iomanip>
#include <iostream>
#include <sstream>

int main() {
    std::string name = "John";
    double salary = 5000.927;

    std::string s;

    // can't add a string to a double:
    //s = name + ": " + salary;

    // so we use a string stream
    std::stringstream ss;
    // fixed: use non-scientific notation for numbers (5000, not 5e+3)
    // setprecision: number of digits after the point
    ss << name << ": " << std::fixed << std::setprecision(2) << salary;
    s = ss.str();

    std::cout << s << std::endl;

    return 0;
}
