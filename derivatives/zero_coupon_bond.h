// derivatives/call_option

#pragma once

#include "derivative.h"
#include "../instruments.h"

#include <algorithm>

class ZeroCouponBond : public Derivative {

    private:
        double r;
        double T;

    public:
        ZeroCouponBond(
            double r_,  
            double T_
        ) 
        :
          r(r_),  
          T(T_)
        {}

        double payoff(double ST) const override {
            return 1;
        }

        double analytical_price() const override {
            return zero_coupon_bond(
                r,
                T
            );
        }

        std::string name() const override {
            return "Zero Coupon Bond";
        }
};
