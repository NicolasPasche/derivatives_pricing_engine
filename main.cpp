#include "instruments.h"
#include "test_utils.h"
#include "random_generator.h"
#include "monte_carlo.h"
#include "mc_payoffs.h"

#include <cmath>
#include <iostream>
#include <fstream>

int main() {

    // Testing the Monte Carlo Engine

    // RNG 
    RandomGenerator rng(1);

    // Market parameters
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double d = 0.00;
    double sigma = 0.20;
    double T = 1.0;

    int num_simulations = 100000;

    // Monte Carlo payoff
    auto payoff = call_payoff(K);

    // Monte Carlo price
    double mc_price = monte_carlo_price(
        S0, 
        r, 
        d, 
        sigma, 
        T, 
        num_simulations, 
        rng, 
        payoff
    );

    // Analytical Black-Scholes price
    double bs_price = call_price(
        S0, 
        K, 
        r, 
        d, 
        sigma, 
        T
    );

    std::cout << "Prices for Call Option" << std::endl;
    std::cout << "Analytical Black-Scholes Price: " << bs_price << std::endl;
    std::cout << "Numerical Monte Carlo Price: " << mc_price << std::endl;

    /*

    Writing some test just to make sure the vanilla black scholes engine works and 
    all the instruments are implemented correctly


    double S = 100;
    double K = 100;
    double r = 0.05;
    double d = 0.00;
    double sigma = 0.20;
    double T = 1.0;
    
    std::cout << "------------------------------" << std::endl;
    std::cout << "Tests" << std::endl;
    std::cout << "------------------------------" << std::endl;

    // Print all prices
    std::cout << "Print all prices" << std::endl;
    std::cout << print_all_prices(S, K, r, d, sigma, T) << std::endl;

    // Put-Call parity check
    std::cout << "Put-Call parity check" << std::endl;
    bool put_call_parity = put_call_parity_check(S, K, r, d, sigma, T);
    std::cout << "Put-Call parity holds: " << put_call_parity << std::endl;

    // Digital Put-Call parity check
    std::cout << "Digital Put-Call parity check" << std::endl;
    bool digital_parity = digital_put_call_parity_check(S, K, r, d, sigma, T);
    std::cout << "Digital Put-Call parity holds: " << digital_parity << std::endl;

    // Call value range check
    std::cout << "Call option price between S and S - K * e(-r * T)" << std::endl;
    bool call_range_check = call_value_range_check(S, K, r, d, sigma, T);
    std::cout << "Call value range check holds: " << call_range_check << std::endl;

    if (call_range_check == false) {
        std::cout << "Call price is out of range!" << std::endl;
        double call_price_value = call_price(S, K, r, d, sigma, T);
        std::cout << "Call price: " << call_price_value << std::endl;
        std::cout << "Lower bound: " << S - K * std::exp(-r * T) << " Upper bound: " << S << std::endl;
    }
*/

/*
    // Collect data for different plots in python
    // Testing the Call Option
    // Call price vs Strike
    std::ofstream file_strike("call_vs_strike.csv");

    file_strike << "Strike,CallPrice\n";

    for (double strike = 50; strike <= 150; strike += 2) {

        double C = call_price(S, strike, r, d, sigma, T);
        file_strike << strike << "," << C << "\n";

    }

    file_strike.close();


    // Call price vs Volatility
    std::ofstream file_vol("call_vs_vol.csv");

    file_vol << "Vol,CallPrice\n";

    for (double vol = 0.05; vol <= 0.50; vol += 0.01) {

        double C = call_price(S, K, r, d, vol, T);
        file_vol << vol << "," << C << "\n";

    }

    file_vol.close();


    // Call price vs Spot
    std::ofstream file_spot("call_vs_spot.csv");

    file_spot << "Spot,CallPrice\n";

    for (double spot = 50; spot <= 150; spot += 2) {

        double C = call_price(spot, K, r, d, sigma, T);
        file_spot << spot << "," << C << "\n";

    }

    file_spot.close();


    // Testing the Put Option
    // Put price vs Strike
    std::ofstream file_put_strike("put_vs_strike.csv");

    file_put_strike << "Strike,PutPrice\n";

    for (double strike = 50; strike <= 150; strike += 2) {

        double C = put_price(S, strike, r, d, sigma, T);
        file_put_strike << strike << "," << C << "\n";

    }

    file_put_strike.close();

    // Put price vs Spot
    std::ofstream file_put_spot("put_vs_spot.csv");

    file_put_spot << "Spot,PutPrice\n";

    for (double spot = 50; spot <= 150; spot += 2) {

        double C = put_price(spot, K, r, d, sigma, T);
        file_put_spot << spot << "," << C << "\n";

    }

    file_put_spot.close();

    // Put price vs Volatility
    std::ofstream file_put_vol("put_vs_vol.csv");

    file_put_vol << "Vol,PutPrice\n";

    for (double vol = 0.05; vol <= 0.50; vol += 0.01) {

        double C = put_price(S, K, r, d, vol, T);
        file_put_vol << vol << "," << C << "\n";

    }

    file_put_vol.close();
*/

}
        
