# include "math_utils.h"
# include "instruments.h"
# include <cmath>

double norm_cdf(double x) {

    // Compute the cumulative probability
    // using the complementary error function
    return 0.5 * std::erfc(-x / std::sqrt(2));
}

double d1(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
) {
    return (std::log(S / K ) + (r - d*T + 0.5 * sigma * sigma) * T) / sigma * std::sqrt(T);
}

double d2(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
) {
    return d1(S, K, r, d, sigma, T) - sigma * std::sqrt(T);
}
