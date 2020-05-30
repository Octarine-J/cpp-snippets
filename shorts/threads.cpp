#include <iostream>
#include <thread>
using namespace std::chrono;

void print(const std::string& s) {
    std::cout << s << std::endl;
    
    std::this_thread::sleep_for(milliseconds(100));
}

int main() {
    auto start = high_resolution_clock::now();

    std::thread t1(print, "hello, world");
    std::thread t2(print, "konnichiwa");

    t1.join();
    t2.join();

    auto finish = high_resolution_clock::now();
    auto delta = duration_cast<milliseconds>(finish - start);

    std::cout << "Executed in " << delta.count() << " ms.\n"; 

    return 0;
}
