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

double monte_carlo_price(
    double S0, 
    double r, 
    double d, 
    double sigma, 
    double T, 
    int num_simulations, 
    RandomGenerator& rng, 
    std::function<double(double)> payoff
)  {
        double payoff_sum = 0.0;

        for (int i = 0; i < num_simulations; ++i) {
            double ST = simulate_terminal_price(
                S0, 
                r, 
                d, 
                sigma, 
                T, 
                rng
            );

        payoff_sum += payoff(ST);

    }

    double average_payoff = payoff_sum / num_simulations;

    // Discount
    return std::exp(-r * T) * average_payoff;
}