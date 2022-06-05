# Write a program to calculate the calorific value of a solid fuel by taking the Bomb calorimeter data from user.

x = float(input("Enter the mass of the solid fuel(x)(in g) : "))
W = float(input("Enter the mass of water(W)(in g) : "))
w = float(input("Enter water equivalent of calorimeter(w)(in g) : "))
T = float(input("Enter the temperature change of water(∆T) : "))
H = float(input("Enter the percentage of Hydrogen(H) : "))
S = float(input("Enter the specific heat of water(S)(in cal/g) : "))

gcv = ((W+w)*T)/x
print("\nGross Calorific Value(gcv) = ((W+w)*T)/x")
print("Gross Calorific Value =", round(gcv, 3), "cal/g")

ncv = gcv-0.09*H*S
print("\nNet Calorific Value(ncv) = gcv-0.09*H*S")
print("Net Calorific Value =", round(ncv, 3), "cal/g")
