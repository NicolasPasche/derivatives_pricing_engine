#include "test_utils.h"
#include "instruments.h"

#include <cmath>
#include <string>

std::string print_all_prices(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
) {
    double zcb = zero_coupon_bond(r, T);
    double forward = forward_price(S, K, r, d, T);

    double call = call_price(S, K, r, d, sigma, T);
    double put = put_price(S, K, r, d, sigma, T);
    
    double dig_c = digital_call_price(S, K, r, d, sigma, T);
    double dig_p = digital_put_price(S, K, r, d, sigma, T);

    std::string result;
    result += "Zero-Coupon Bond price: " + std::to_string(zcb) + "\n";
    result += "Forward price: " + std::to_string(forward) + "\n";
    result += "Call price: " + std::to_string(call) + "\n";
    result += "Put price: " + std::to_string(put) + "\n";
    result += "Digital call price: " + std::to_string(dig_c) + "\n";
    result += "Digital put price: " + std::to_string(dig_p) + "\n";

    return result;
}

bool put_call_parity_check(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
) {
    double lhs =
        call_price(S, K, r, d, sigma, T)
      - put_price(S, K, r, d, sigma, T);

    double rhs =
        S * std::exp(-d * T) - K * std::exp(-r * T);

    return (std::abs(lhs - rhs) < 1e-6);
}

bool digital_put_call_parity_check(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
) {
    double lhs = digital_call_price(S, K, r, d, sigma, T) + digital_put_price(S, K, r, d, sigma, T);
    double rhs = std::exp(-r * T);

    return (std::abs(lhs - rhs) < 1e-6);
}

bool call_value_range_check(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
) {
    double C = call_price(S, K, r, d, sigma, T);
    return (C <= S && C >= S - K * std::exp(-r * T));
}
