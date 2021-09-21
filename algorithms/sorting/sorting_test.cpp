#include <random>
#include <vector>
#include <list>
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"

#define CATCH_CONFIG_MAIN
#include "../../include/catch.hpp"

template <typename Iterator>
using SortingAlgorithm = void (*)(Iterator, Iterator);

class SortingTestFixture {
private:
    // actual, expected
    const std::vector<std::pair<std::vector<int>, std::vector<int>>> data = {
            {{}, {}},
            {{1}, {1}},
            {{2, 1}, {1, 2}},
            {{1, 2}, {1, 2}},
            {{3, 2, 1}, {1, 2, 3}},
            {{1, 2, 3}, {1, 2, 3}},
            {{1, 3, 2}, {1, 2, 3}},
            {{3, 1, 7, 2, 4, 5, 9, 8, 6}, {1, 2, 3, 4, 5, 6, 7, 8, 9}},
            {{1, 3, 3, 2, 1, 2}, {1, 1, 2, 2, 3, 3}}
    };

    static const size_t RandomTestVectorSize = 100;

public:
    void test_sorting(SortingAlgorithm<std::vector<int>::iterator> sort) {
        for (const auto& item : data) {
            auto input = item.first;
            const auto& expected = item.second;

            sort(input.begin(), input.end());

            REQUIRE( expected == input );
        }
    }

    static void random_test_sorting(SortingAlgorithm<std::vector<int>::iterator> sort) {
        std::random_device rd;
        std::mt19937 generator(rd());
        auto distribution = std::uniform_int_distribution<>(-99, 99);

        // fill in test vector
        std::vector<int> input(RandomTestVectorSize);
        for (int& value : input) {
            value = distribution(generator);
        }

        sort(input.begin(), input.end());

        for (int i = 1; i < RandomTestVectorSize; ++i) {
            REQUIRE( input[i-1] <= input[i] );
        }
    }
};

TEST_CASE_METHOD( SortingTestFixture, "BubbleSort" ) {
    test_sorting(alg::sorting::bubble_sort);
    random_test_sorting(alg::sorting::bubble_sort);
}

TEST_CASE_METHOD( SortingTestFixture, "InsertionSort" ) {
    test_sorting(alg::sorting::insertion_sort);
    random_test_sorting(alg::sorting::insertion_sort);
}

TEST_CASE_METHOD( SortingTestFixture, "SelectionSort" ) {
    test_sorting(alg::sorting::selection_sort);
    random_test_sorting(alg::sorting::selection_sort);
}
