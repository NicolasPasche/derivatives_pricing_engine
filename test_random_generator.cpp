#include <iostream>
#include <vector>
#include <cmath>

#include "random_generator.h"

int main() {

    int dimension = 1;
    int num_samples = 1000000;

    RandomGenerator rng(dimension);

    double sum = 0.0;
    double sum_sq = 0.0;

    for (int i = 0; i < num_samples; i++) {

        std::vector<double> Z = rng.get_normal_vector();

        double z = Z[0];

        sum += z;
        sum_sq += z * z;

    }

    double mean = sum / num_samples;
    double variance = (sum_sq / num_samples) - (mean * mean);

    RandomGenerator rng2(5);

    auto Z = rng2.get_normal_vector();



    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Variance: " << variance << std::endl;
    std::cout << "Vector size: " << Z.size() << std::endl;

    return 0;
}