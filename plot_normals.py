import pandas as pd # type: ignore
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm

data = pd.read_csv("normal_samples.csv", header=None
)

samples = data[0]

# Plot 1: Histogram only

plt.figure()
plt.hist(samples, bins=100)
plt.title("Histogram of Generated Normal Random Numbers")
plt.xlabel("Z")
plt.ylabel("Frequency")
plt.show()


# Plot 2: Histogram + Theorie

plt.figure()

plt.hist(samples, bins=100, density=True)

# Theoretical Normal Distribution
x = np.linspace(-4, 4, 500)

plt.plot(x, norm.pdf(x, 0, 1))

plt.title("Histogram vs Theoretical Normal Distribution")
plt.xlabel("Z")
plt.ylabel("Density")
plt.show()