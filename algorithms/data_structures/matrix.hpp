#pragma once

#include <memory>
#include <stdexcept>

namespace ds {

    template<typename T>
    class matrix {
    private:
        size_t n;
        size_t m;
        std::unique_ptr<T[]> values;
    public:
        matrix(size_t n, size_t m) : n(n), m(m) {
            if (n == 0 || m == 0) {
                throw std::invalid_argument("Matrix dimensions should be positive.");
            }

            values = std::make_unique<T[]>(n * m);
        }

        matrix(size_t n, size_t m, T default_value) : matrix(n, m) {
            for (size_t i = 0; i < m * n; ++i) {
                values[i] = default_value;
            }
        }

        T operator()(size_t i, size_t j) const {
            return values[i * m + j];
        }

        T& operator()(size_t i, size_t j) {
            return values[i * m + j];
        }
    };

}
