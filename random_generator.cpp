#include "random_generator.h"

/*
    Constructor initializes the random number generator.

    dimension determines how many random numbers are generated per path.
*/

RandomGenerator::RandomGenerator(int dim)
    : generator(std::random_device{}()),
      distribution(0.0, 1.0),
      dimension(dim)
{}

/*
    Returns a vector of normally distributed random numbers.

    Each Monte Carlo path requires 'dimension' random numbers.
*/

std::vector<double>
RandomGenerator::get_normal_vector() {

    std::vector<double> result(dimension);

    for (int i = 0; i < dimension; i++) {

        result[i] = distribution(generator);

    }

    return result;
} 