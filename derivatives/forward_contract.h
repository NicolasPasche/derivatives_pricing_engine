// derivatives/call_option

#pragma once

#include "derivative.h"
#include "../instruments.h"

#include <algorithm>

class ForwardContract : public Derivative {

    private:
        double S0;
        double K;
        double r;
        double d;
        double T;

    public:
        ForwardContract(
            double S0_, 
            double K_, 
            double r_, 
            double d_, 
            double T_
        )
        : S0(S0_), 
          K(K_), 
          r(r_), 
          d(d_), 
          T(T_)
        {}

        double payoff(double ST) const override {
            return ST - K;
        }

        double analytical_price() const override {
            return forward_price(
                S0, 
                K, 
                r, 
                d, 
                T
            );
        }

        std::string name() const override {
            return "Forward Contract";
        }
};
