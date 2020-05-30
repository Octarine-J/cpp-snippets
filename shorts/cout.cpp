#include <iomanip>
#include <iostream>

int main() {
    std::cout << "hello, world";
    std::cout << std::endl; // flushes the buffer!

    std::cerr << "An error message goes to std::cerr" << std::endl;

    // clog is a buffered version of cerr
    std::clog << "std::clog stream is used for logging" << std::endl;

    // print boolean (as "true" or "false")
    bool b {true};
    std::cout << std::boolalpha << b << std::endl;

    // print hex
    int h {0xff};
    std::cout << std::hex << std::showbase << h << std::endl;
    std::cout << std::dec;  // undo hex

    // print a formatted number (000123)
    std::cout << std::setfill('0') << std::setw(6) << 123 << std::endl;
    std::cout << std::setfill(' ');  // undo fill

    // print a floating point number
    double a = 27.9876125;  // setprecision: total 5 digits (before and after the dot)
    std::cout << std::setprecision(5) << a << std::endl;

    // set current locale (for monetary and date/time output)
    std::cout.imbue(std::locale(""));

    // print monetary amount
    std::cout << std::put_money("12000") << std::endl;

    // print date/time
    time_t ts = std::time(nullptr);
    tm* localTs = std::localtime(&ts);
    std::cout << std::put_time(localTs, "%c") << std::endl;

    // raw output to the stream
    std::cout.write("raw output", 10);
    std::cout.put('\n');

    if (std::cout.good()) {
        std::cout << "stream is OK (and not EOF)" << std::endl;
    }

    if (std::cout.bad()) {
        std::clog << "a fatal error occurred (EOF is not considered a fatal error)\n";
    }

    if (std::cout.fail()) {  // or  if (!cout) { ... }
        std::cout << "last operation on stream failed (EOF is not a failure)" << std::endl;
    }

    // force stream to use exceptions
    std::cout.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);
    try {
        std::cout << "hello" << std::endl;
    } catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << " (code " << e.code() << ")\n";
    }
    std::cout.clear();  // clear error state of the stream

    return -1;
}
