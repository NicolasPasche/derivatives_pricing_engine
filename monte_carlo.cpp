#include "monte_carlo.h"
#include <cmath>

double simulate_terminal_price(
    double S0, 
    double r, 
    double d, 
    double sigma, 
    double T, 
    RandomGenerator& rng
) {
    std::vector<double> W = rng.get_normal_vector();
    
    double ST = S0 * std::exp((r - d - 0.5 * sigma * sigma) * T + sigma * std::sqrt(T) * W[0]);

    return ST;
}