#pragma once

#include <functional>

// Payoff functions for various types of options and financial instruments.
std::function<double(double)> call_payoff(double K);

std::function<double(double)> put_payoff(double K);

std::function<double(double)> digital_call_payoff(double K);

std::function<double(double)> digital_put_payoff(double K);

std::function<double(double)> forward_payoff(double K); // First I accidently used forward level. Not payoff. Bug fixed

std::function<double(double)> zcb_payoff(double T);