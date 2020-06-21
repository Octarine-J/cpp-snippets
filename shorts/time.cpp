#include <chrono>
#include <ctime>    // for strftime
#include <iomanip>  // for put_time
#include <iostream>
#include <string>
#include <vector>
using namespace std::chrono;


int main() {
    system_clock::time_point t_point = system_clock::now();
    time_t tt = system_clock::to_time_t(t_point);
    tm* t = localtime(&tt);

    // print current time
    std::cout << std::put_time(t, "%H:%M:%S") << std::endl;

    // convert to a string
    char buffer[80] = {0};
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S", t);

    std::cout << buffer << std::endl;

    // can also measure time
    auto start = high_resolution_clock::now();

    std::vector<std::string> temp(10000);

    auto end = high_resolution_clock::now();
    auto time_ms = duration_cast<nanoseconds>(end - start).count();

    std::cout << "Executed in " << time_ms << " ns" << std::endl;
}
