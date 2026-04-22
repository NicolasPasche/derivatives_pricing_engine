#pragma once

#include "../random_generator.h"
#include "../derivatives/derivative.h"

class MonteCarloEngine {
    private:
        double S0;
        double r;
        double d;
        double sigma;
        double T;

        int num_simulations;

        RandomGenerator& rng;

    public:
        MonteCarloEngine(
            double S0_, 
            double r_, 
            double d_, 
            double sigma_, 
            double T_, 
            int num_simulations_,
            RandomGenerator& rng  
        );

        double simulate_terminal_price();

        double price(const Derivative& derivative);
};