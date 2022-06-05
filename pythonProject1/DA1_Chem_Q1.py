# Write a program to predict whether a reaction is spontaneous or not by taking the required data from user.

H = float(input("Enter the change in Enthalpy(∆H) (in kJ/mol): "))
S = float(input("Enter the change in Entropy(∆S) (in kJ/K.mol): "))
T = float(input("Enter the Temperature(T) (in K): "))
G = H - T*S
print("\n∆G = ∆H - T*∆S")
if G < 0:
    print("∆G =", G, "kJ")
    print("The reaction is Spontaneous at", T, "K")
elif G == 0:
    print("The reaction is at Equilibrium.")
else:
    print("∆G =", G, "kJ")
    print("The reaction is NOT Spontaneous at", T, "K")
