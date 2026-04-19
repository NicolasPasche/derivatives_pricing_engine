# include "instruments.h"
# include "math_utils.h"
# include <cmath>



double zero_coupon_bond(
    double r, 
    double T
) { 
    return std::exp(-r * T);
}

double forward_price(
    double S, 
    double K,
    double r, 
    double d, 
    double T
) {
    return S * std::exp(-d * T) - K * std::exp(-r * T);
}

double call_price(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
) {
    double D1 = d1(S, K, r, d, sigma, T);
    double D2 = d2(S, K, r, d, sigma, T);    

    return S * std::exp(-d * T) * norm_cdf(D1) - K * std::exp(-r * T) * norm_cdf(D2);
}

double put_price(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
) {
    double D1 = d1(S, K, r, d, sigma, T);
    double D2 = d2(S, K, r, d, sigma, T);

    return K * std::exp(-r * T) * norm_cdf(-D2) - S * std::exp(-d * T) * norm_cdf(-D1);
}

double digital_call_price(
    double S,
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
) {
    double D2 = d2(S, K, r, d, sigma, T);

    return std::exp(-r * T) * norm_cdf(D2);
}

double digital_put_price(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
) {
    double D2 = d2(S, K, r, d, sigma, T);

    return std::exp(-r * T) * norm_cdf(-D2);
}