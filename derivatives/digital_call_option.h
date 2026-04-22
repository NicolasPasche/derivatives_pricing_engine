#pragma once

#include "derivative.h"
#include "../instruments.h"

class DigitalCallOption : public Derivative {

private:

    double S0;
    double K;
    double r;
    double d;
    double sigma;
    double T;

public:

    DigitalCallOption(
        double S0_,
        double K_,
        double r_,
        double d_,
        double sigma_,
        double T_
    )
    : S0(S0_),
      K(K_),
      r(r_),
      d(d_),
      sigma(sigma_),
      T(T_)
    {}

    double payoff(double ST) const override {

        if (ST > K)
            return 1.0;
        else
            return 0.0;

    }

    double analytical_price() const override {

        return digital_call_price(
            S0,
            K,
            r,
            d,
            sigma,
            T
        );

    }

    std::string name() const override {

        return "Digital Call Option";

    }

};