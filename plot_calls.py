import matplotlib.pyplot as plt
import csv

# Plots for Call Options
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

# ------------------------------------------------
# ------------------------------------------------

# Plots for Put Options
# Plot put vs strike
K_put_strike = []
P_put_strike = []

with open("put_vs_strike.csv") as f:
    reader_put_strike = csv.DictReader(f)

    for row in reader_put_strike:
        K_put_strike.append(float(row["Strike"]))
        P_put_strike.append(float(row["PutPrice"]))

plt.plot(K_put_strike, P_put_strike)
plt.xlabel("Strike")
plt.ylabel("Put Price")
plt.title("Put Price vs Strike")

plt.show()

# ------------------------------------------------

# Plot put vs spot
S_put_spot = []
P_put_spot = []

with open("put_vs_spot.csv") as f:
    reader_put_spot = csv.DictReader(f)

    for row in reader_put_spot:
        S_put_spot.append(float(row["Spot"]))
        P_put_spot.append(float(row["PutPrice"]))

plt.plot(S_put_spot, P_put_spot)
plt.xlabel("Spot Price")
plt.ylabel("Put Price")
plt.title("Put Price vs Spot Price")

plt.show()

# ------------------------------------------------

# Plot put vs vol
Sigma_put_vol = []
P_put_vol = []

with open("put_vs_vol.csv") as f:
    reader_put_vol = csv.DictReader(f)

    for row in reader_put_vol:
        Sigma_put_vol.append(float(row["Vol"]))
        P_put_vol.append(float(row["PutPrice"]))

plt.plot(Sigma_put_vol, P_put_vol)
plt.xlabel("Volatility")
plt.ylabel("Put Price")
plt.title("Put Price vs Volatility")

plt.show()