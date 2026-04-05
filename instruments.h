# pragma once

double zero_coupon_bond(
    double r, 
    double T
);

double forward_price(
    double S, 
    double r, 
    double d, 
    double T
);

double call_price(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
);

double put_price(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
);

double digital_call_price(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
);

double digital_put_price(
    double S, 
    double K, 
    double r, 
    double d, 
    double sigma, 
    double T
);