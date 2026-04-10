#pragma once

#include <vector>
#include <random>

/*
    This class generatres normally distributed random numbers.

    The idea is to allow easy replacement of the random number generator later on (e.g. Sobol sequences or other generators).

    The generator returns a vecotr of normally distributet numbers. The Size of this vector is the dimensionality of the simulation
*/

class RandomGenerator {

    private:
        std::mt19937 generator; // Mersenne Twister random number generator
        std::normal_distribution<double> distribution;

        int dimension;

    public:

        // Constructor
        RandomGenerator(int dim);

        // Generate a vector of normal random numbers
        std::vector<double> get_normal_vector();

};