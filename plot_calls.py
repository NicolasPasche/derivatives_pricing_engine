import matplotlib.pyplot as plt
import csv

# Plot call vs strike
K_strike = []
C_strike = []

with open("call_vs_strike.csv") as f:
    reader_strike = csv.DictReader(f)

    for row in reader_strike:
        K_strike.append(float(row["Strike"]))
        C_strike.append(float(row["CallPrice"]))

plt.plot(K_strike, C_strike)
plt.xlabel("Strike")
plt.ylabel("Call Price")
plt.title("Call Price vs Strike")

plt.show()

# ------------------------------------------------

# Plot call vs spot

S_spot = []
C_spot = []

with open("call_vs_spot.csv") as f:
    reader_spot = csv.DictReader(f)

    for row in reader_spot:
        S_spot.append(float(row["Spot"]))
        C_spot.append(float(row["CallPrice"]))

plt.plot(S_spot, C_spot)
plt.xlabel("Spot Price")
plt.ylabel("Call Price")
plt.title("Call Price vs Spot Price")

plt.show()

# ------------------------------------------------

# Plot call vs vol

Sigma_vol = []
C_vol = []

with open("call_vs_vol.csv") as f:
    reader_vol = csv.DictReader(f)

    for row in reader_vol:
        Sigma_vol.append(float(row["Vol"]))
        C_vol.append(float(row["CallPrice"]))

plt.plot(Sigma_vol, C_vol)
plt.xlabel("Volatility")
plt.ylabel("Call Price")
plt.title("Call Price vs Volatility")

plt.show()