#include "include/args.hpp"
#include "include/random.hpp"

#include <fstream>
#include <iostream>

void write_random_ints(std::string filename, size_t n, int lower_bound, int upper_bound) {
    auto vec = random_int_vector(n, lower_bound, upper_bound);
    
    std::ofstream f(filename);
    
    for (int value : vec) {
        f << value << "\n";
    }
}

int main(int argc, char *argv[]) {
    auto args = parse_args(argc, argv);
    
    std::string filename = args["filename"].or_default("data.txt");
    size_t n = args["n"].or_default(1'000'000);
    int lower_bound = args["low"].or_default(1);
    int upper_bound = args["high"].or_default(99);

    write_random_ints(filename, n, lower_bound, upper_bound);
}
