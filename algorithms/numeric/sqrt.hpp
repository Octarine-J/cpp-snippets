#pragma once

#include <stdexcept>

namespace numeric {

    double c_epsilon = 1e-9;

    class max_iteration_exceeded : public std::runtime_error {
    public:
        max_iteration_exceeded() :
            std::runtime_error("maximum number of iterations exceeded") {}
    };

    double abs(double a) {
        return (a < 0) ? -a : a;
    }

    double sqrt(double a) {
        static int max_iter = 1000;
        int iter = 1;

        double x0 = a / 2;

        while (numeric::abs(x0 * x0 - a) >= c_epsilon) {

            x0 = x0 / 2.0 + a / (2 * x0);

            ++iter;

            if (iter > max_iter) {
                throw numeric::max_iteration_exceeded();
            }
        }

        return x0;
    }

}

