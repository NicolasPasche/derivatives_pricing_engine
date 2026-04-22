// derivatives/derivative.h

#pragma once

#include <string>

class Derivative {

    public:
        virtual double payoff(double ST) const = 0;
        virtual double analytical_price() const = 0;
        virtual std::string name() const = 0;
        virtual ~Derivative() {}
};