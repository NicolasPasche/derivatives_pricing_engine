#include "monte_carlo.h"
#include "random_generator.h"

#include <iostream>

int main() {

    RandomGenerator rng(1);

    double S0 = 100.0; 
    double r = 0.05; 
    double d = 0.00;
    double sigma = 0.02;
    double T = 1.0;

    int num_simulations = 100000;

    double sum_terminal_prices = 0.0;

    for (int i = 0; i < num_simulations; ++i) {
        double ST = simulate_terminal_price(S0, r, d, sigma, T, rng);
        sum_terminal_prices += ST;
    }

    double average_terminal_price = sum_terminal_prices / num_simulations;
    std::cout << "Average Terminal Price after " << num_simulations << " simulations: " << average_terminal_price << std::endl;
    std::cout << "Expected Terminal Price (Analytical): " << S0 * std::exp((r - d) * T) << std::endl;

    return 0;
}
