# Derivatives Pricing Engine (C++)

**Author:** Nicolas Pasche  
**Project Type:** Quantitative Finance / Numerical Methods  
**Language:** C++ (core), Python (visualisation)

---

## Project Overview

This project implements a modular **derivatives pricing engine** written in C++.  
The focus is on building pricing models **from first principles**, validating them mathematically, and visualising results using Python.

The current implementation supports **analytical Black–Scholes pricing** and includes a custom **random number generator** in preparation for **Monte Carlo simulation**.

The long-term goal is to extend the engine to include **numerical pricing methods**, **stochastic simulations**, and potentially **machine learning-based surrogate models**.

---

## Implemented Features

### Analytical Pricing — Black-Scholes

The following European option pricing functions are implemented:

- European Call Option
- European Put Option
- Digital Options
- Put-Call Parity verification
- Arbitrage Bounds
- Monotonicity Tests
- Convexity Tests

The implementation is modular and designed to allow easy extension to additional derivatives.

---

### Random Number Generation

A custom **normal random number generator** has been implemented to support Monte Carlo simulations.

Validation tests include:

- Mean test (expected ≈ 0)
- Variance test (expected ≈ 1)
- Histogram analysis
- Comparison with theoretical normal distribution

Example output:

- Mean: -0.0006
- Variance: 0.9997


This confirms correct statistical behaviour of the generator.

---

### Visualisation (Python)

Python scripts are used to visualise pricing behaviour and validate mathematical properties.

Generated plots include:

#### Call Option Plots

- Call price vs Spot
- Call price vs Strike
- Call price vs Volatility

#### Put Option Plots

- Put price vs Spot
- Put price vs Strike
- Put price vs Volatility

#### RNG Validation

- Histogram of generated normal samples
- Histogram vs theoretical normal distribution

---

# Mathematical Models

## Black-Scholes Model

The implemented pricing formulas are based on:

$$S_T = S_0 \exp\left(\left(r - \frac{1}{2}\sigma^2\right)T + \sigma\sqrt{T}Z\right)$$

where:

- $S_0$ = initial stock price
- $r$ = risk-free rate
- $\sigma$ = volatility
- $T$ = maturity
- $Z \sim \mathcal{N}(0,1)$

---

# Current Development Status

## Completed

- Black-Scholes pricing implementation
- Put and Call pricing validation
- RNG implementation
- RNG statistical testing
- Pricing visualisations
- Git version control integration

## In Progress

- Monte Carlo pricing engine

## Planned

- Monte Carlo pricing for European options
- Confidence interval estimation
- Variance reduction methods
- Path-dependent derivatives
- Model extensions beyond Black-Scholes

---

# Next Milestone

## Monte Carlo Simulation

Planned features:

- Terminal price simulation
- Monte Carlo estimator
- Convergence analysis
- Comparison with analytical Black-Scholes prices

This will allow validation of numerical pricing accuracy.

---

# Technologies Used

## Core

- C++17
- Standard Library (STL)

## Visualisation

- Python 3
- NumPy
- Matplotlib
- SciPy

## Development

- Git
- GitHub
- VS Code

---

# Design Philosophy

This project focuses on:

- Mathematical correctness
- Modular software design
- Numerical stability
- Reproducibility
- Extensibility

The architecture is intentionally modular to support future additions such as:

- Monte Carlo engines
- Variance reduction techniques
- Stochastic models
- Machine learning methods

--- 

# Future Extensions

## For school project

- Merton Jump-Diffusion model
- GPU acceleration
- Neural network surrogate pricing (ANN and maybe PINN)

## After I've finished the school project

- Stochastic volatility models
- Calibration algorithms
- Greeks and hedging strategies