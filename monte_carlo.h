#pragma once

#include "random_generator.h"

#include <functional>

double simulate_terminal_price(
    double S0, 
    double r, 
    double d, 
    double sigma, 
    double T, 
    RandomGenerator& rng
);

double monte_carlo_price(
    double S0, 
    double r, 
    double d, 
    double sigma, 
    double T, 
    int num_simulations, 
    RandomGenerator& rng, 
    std::function<double(double)> payoff
);