// Stuff for OOP Engine
#include "derivatives/derivative.h"
#include "derivatives/call_option.h"
#include "derivatives/put_option.h"
#include "derivatives/digital_call_option.h"
#include "derivatives/digital_put_option.h"
#include "derivatives/forward_contract.h"
#include "derivatives/zero_coupon_bond.h"

// Monte Carlo OOP Engine
#include "engines/monte_carlo_engine.h"

#include <memory>
#include <vector>

// Function based pricing stuff
#include "instruments.h"
#include "test_utils.h"

// Monte Carlo Stuff
#include "random_generator.h"
#include "monte_carlo.h"
#include "mc_payoffs.h"

// Just stuff for general purpose
#include <cmath>
#include <iostream>
#include <fstream>

int main() {
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

    // Testing new OOP stuff (derivatives and monte carlo)
    // Initializing Monte Carlo Engine
    MonteCarloEngine mc(
        S0, 
        r, 
        d, 
        sigma, 
        T, 
        num_simulations, 
        rng
    );

    // Vector for all derivatives
    std::vector<std::unique_ptr<Derivative>> derivatives;

    // Adding Call Option
    derivatives.push_back(
        std::make_unique<CallOption>(
            S0, K, r, d, sigma, T
        )
    );

    // Adding Put Option
    derivatives.push_back(
        std::make_unique<PutOption>(
            S0, K, r, d, sigma, T
        )
    );

    // Adding Digital Call Option
    derivatives.push_back(
        std::make_unique<DigitalCallOption>(
            S0, K, r, d, sigma, T
        )
    );

    // Adding Digital Put Option
    derivatives.push_back(
        std::make_unique<DigitalPutOption>(
            S0, K, r, d, sigma, T
        )
    );

    // Adding Forward Contract
    derivatives.push_back(
        std::make_unique<ForwardContract>(
            S0, K, r, d, T
        )
    );

    // Adding Zero Coupon Bond
    derivatives.push_back(
        std::make_unique<ZeroCouponBond>(
            r, T
        )
    );

    for (const auto& derivative : derivatives) {

        double analytical = derivative->analytical_price();

        MonteCarloEngine::MCResult result = mc.price(*derivative);
        double mc_price = result.price;
        double standard_error = result.standard_error;

        std::cout << "\nPrices for " << derivative->name() << std::endl;
        std::cout << "Analytical Price: " << analytical << std::endl;
        std::cout << "Monte Carlo Price: " << mc_price << std::endl;
        std::cout << "Standard Error: " << standard_error << std::endl;
    }

    std::cout << "\n------------------------------" << std::endl;
    std::cout << "Tests" << std::endl;

    std::cout << "Put-Call Parity Check: " << put_call_parity_check(S0, K, r, d, sigma, T) << std::endl;
    std::cout << "Digital Put-Call Parity Check: " << digital_put_call_parity_check(S0, K, r, d, sigma, T) << std::endl;
    std::cout << "Call Value Range Check: " << call_value_range_check(S0, K, r, d, sigma, T) << std::endl;

    /*
    // Testing the Monte Carlo Engine
    // Monte Carlo payoff for all derivatives
    auto call_option_payoff = call_payoff(K);
    auto put_option_payoff = put_payoff(K);
    auto digital_call_option_payoff = digital_call_payoff(K);
    auto digital_put_option_payoff = digital_put_payoff(K);
    auto forward_contract_payoff = forward_payoff(K);
    auto zero_coupon_bond_payoff = zcb_payoff(T);

    // Monte Carlo Zero Coupon bond price
    double zcb_mc_price = monte_carlo_price(
        S0, 
        r, 
        d, 
        sigma, 
        T, 
        num_simulations, 
        rng, 
        zero_coupon_bond_payoff
    );

    // Analytical Black-Scholes price
    double bs_zcb_price = zero_coupon_bond(
        r, 
        T
    );

    std::cout << "\nPrices for Zero Coupon Bond" << std::endl;
    std::cout << "Analytical Black-Scholes Price: " << bs_zcb_price << std::endl;
    std::cout << "Numerical Monte Carlo Price: " << zcb_mc_price << std::endl;

    // Monte Carlo Forward price
    double forward_mc_price = monte_carlo_price(
        S0, 
        r, 
        d, 
        sigma, 
        T, 
        num_simulations, 
        rng, 
        forward_contract_payoff
    );

    // Analytical Black-Scholes price
    double bs_forward_price = forward_price(
        S0, 
        K, 
        r, 
        d, 
        T
    );

    std::cout << "\nPrices for Forward Contract" << std::endl;
    std::cout << "Analytical Black-Scholes Price: " << bs_forward_price << std::endl;
    std::cout << "Numerical Monte Carlo Price: " << forward_mc_price << std::endl;

    // Monte Carlo call price
    double call_mc_price = monte_carlo_price(
        S0, 
        r, 
        d, 
        sigma, 
        T, 
        num_simulations, 
        rng, 
        call_option_payoff
    );

    // Analytical Black-Scholes price
    double bs_call_price = call_price(
        S0, 
        K, 
        r, 
        d, 
        sigma, 
        T
    );

    std::cout << "\nPrices for Call Option" << std::endl;
    std::cout << "Analytical Black-Scholes Price: " << bs_call_price << std::endl;
    std::cout << "Numerical Monte Carlo Price: " << call_mc_price << std::endl;

    // Monte Carlo put price
    double put_mc_price = monte_carlo_price(
        S0, 
        r, 
        d, 
        sigma, 
        T, 
        num_simulations, 
        rng, 
        put_option_payoff
    );

    // Analytical Black-Scholes put price
    double bs_put_price = put_price(
        S0, 
        K, 
        r, 
        d, 
        sigma, 
        T
    );

    std::cout << "\nPrices for Put Option" << std::endl;
    std::cout << "Analytical Black-Scholes Price: " << bs_put_price << std::endl;
    std::cout << "Numerical Monte Carlo Price: " << put_mc_price << std::endl;

    // Monte Carlo digital call option price
    double digital_call_mc_price = monte_carlo_price(
        S0, 
        r, 
        d, 
        sigma, 
        T, 
        num_simulations, 
        rng, 
        digital_call_option_payoff
    );

    // Analytical Black-Scholes digital call price
    double bs_digital_call_price = digital_call_price(
        S0, 
        K, 
        r, 
        d, 
        sigma, 
        T
    );

    std::cout << "\nPrices for Digital Call Option" << std::endl;
    std::cout << "Analytical Black-Scholes Price: " << bs_digital_call_price << std::endl;
    std::cout << "Numerical Monte Carlo Price: " << digital_call_mc_price << std::endl;

    // Monte Carlo digital put option price
    double digital_put_mc_price = monte_carlo_price(
        S0, 
        r, 
        d, 
        sigma, 
        T, 
        num_simulations, 
        rng, 
        digital_put_option_payoff
    );

    // Analytical Black-Scholes digital call price
    double bs_digital_put_price = digital_put_price(
        S0, 
        K, 
        r, 
        d, 
        sigma, 
        T
    );

    std::cout << "\nPrices for Digital Put Option" << std::endl;
    std::cout << "Analytical Black-Scholes Price: " << bs_digital_put_price << std::endl;
    std::cout << "Numerical Monte Carlo Price: " << digital_put_mc_price << std::endl;

    */

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
        
