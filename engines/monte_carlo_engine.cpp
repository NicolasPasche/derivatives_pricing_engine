#include "monte_carlo_engine.h"

#include <cmath>

MonteCarloEngine::MonteCarloEngine(
    double S0_, 
    double r_, 
    double d_, 
    double sigma_, 
    double T_, 
    int num_simulations_, 
    RandomGenerator& rng_
)
: S0(S0_), 
  r(r_), 
  d(d_), 
  sigma(sigma_), 
  T(T_), 
  num_simulations(num_simulations_), 
  rng(rng_)
{}

double MonteCarloEngine::simulate_terminal_price() {
    std::vector<double> W = rng.get_normal_vector();

    double ST = S0 * std::exp((r - d - 0.5 * sigma * sigma) * T + sigma * std::sqrt(T) * W[0]);

    return ST;
}

struct MonteCarloEngine::MCResult MonteCarloEngine::price(
    const Derivative& derivative
) {
    double mean = 0.0;
    double M2 = 0.0;
    int n = 0;

    for (int i = 0; i < num_simulations; ++i) {
        double ST = simulate_terminal_price();

        double payoff = derivative.payoff(ST);
        double discounted_payoff = std::exp(-r * T) * payoff;

        n++;
        double delta = discounted_payoff - mean;
        mean += delta / n;
        double delta2 = discounted_payoff - mean;
        M2 += delta * delta2;
    }

    double variance = M2 / (n - 1);
    double standard_error = std::sqrt(variance / n);

    return {mean, standard_error};
} 