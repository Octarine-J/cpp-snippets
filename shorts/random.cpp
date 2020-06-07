#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include <vector>

template <class Container>
void print(const Container& v) {
    for (const auto& value : v) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::random_device rd;
    const auto seed = static_cast<unsigned int>( rd.entropy() ? rd() : std::time(nullptr) );

    std::mt19937 engine(seed);
    auto get_random = std::uniform_int_distribution<>(1, 6);

    for (int i = 0; i < 10; ++i) {
        std::cout << get_random(engine) << " ";
    }
    std::cout << std::endl;


    // can also select a sample from a range of predefined values

    std::vector<std::string> pets = {"cat", "dog", "hamster", "guinea_pig", "racoon"};
    
    size_t num_samples = 3;
    std::vector<std::string> samples(num_samples);

    std::sample(pets.begin(), pets.end(), samples.begin(), num_samples, engine);
    print(samples);


    // shuffle a list of values in O(n)

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    std::shuffle(numbers.begin(), numbers.end(), engine);
    print(numbers);
}
