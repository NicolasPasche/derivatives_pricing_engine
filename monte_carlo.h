#pragma once

#include "random_generator.h"

double simulate_terminal_price(
    double S0, 
    double r, 
    double d, 
    double sigma, 
    double T, 
    RandomGenerator& rng
);