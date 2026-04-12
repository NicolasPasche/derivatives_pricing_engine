#include "mc_payoffs.h"
#include <algorithm>

std::function<double(double)> call_payoff(double K) {
    return [K](double ST) {
        return std::max(ST - K, 0.0);
    };
}

std::function<double(double)> put_payoff(double K) {
    return [K](double ST) {
        return std::max(K - ST, 0.0);
    };
}

std::function<double(double)> digital_call_payoff(double K) {
    return [K](double ST) {
        return ST > K ? 1.0 : 0.0;
    };
}

std::function<double(double)> digital_put_payoff(double K) {
    return [K](double ST) {
        return ST < K ? 1.0 : 0.0;
    };
}

std::function<double(double)> forward_payoff(double K) {
    return [K](double ST){
        return ST - K;
    };
}

std::function<double(double)> zcb_payoff(double K) {
    return [](double ST){
        return 1.0;
    };
}