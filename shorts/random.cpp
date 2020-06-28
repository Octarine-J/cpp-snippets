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

template <class T, class Random>
std::vector<T> random_vector(size_t n, const Random& get_random) {
    std::vector<T> result(n);
    std::generate(result.begin(), result.end(), get_random);
    return result;
}

int main() {
    std::random_device rd;
    const auto seed = static_cast<std::mt19937::result_type>(
        rd.entropy() ? rd() : std::time(nullptr)
    );

    std::mt19937 engine(seed);  // Mersenne twister with all 14 parameters predefined
    auto int_distribution = std::uniform_int_distribution<>(1, 6);
    auto get_random = std::bind(int_distribution, engine);

    auto random_ints = random_vector<int>(10, get_random);
    print(random_ints);

    auto real_distribution = std::uniform_real_distribution<>(0.0, 1.0);
    auto random_reals = random_vector<double>(10, std::bind(real_distribution, engine));
    print(random_reals);

    // also available:
    // bernoulli_distribution; binomial_distribution; poisson_distribution;
    // geometric_distribution; normal_distribution; etc.


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
