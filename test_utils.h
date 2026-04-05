# pragma once
#include <string>

std::string print_all_prices(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
);


bool put_call_parity_check(
    double S,
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
);

bool digital_put_call_parity_check(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
);

bool call_value_range_check(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
);