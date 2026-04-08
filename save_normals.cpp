#include <fstream>
#include "random_generator.h"

int main() {

    RandomNumberGenerator rng(1);

    std::ofstream file("normal_samples.csv");

    int num_samples = 100000;

    for (int i = 0; i < num_samples; i++) {

        auto Z = rng.get_normal_vector();

        file << Z[0] << "\n";

    }

    file.close();

    return 0;
}