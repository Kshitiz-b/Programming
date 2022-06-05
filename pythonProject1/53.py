# Take input from the user to make a dictionary and print out the capital of country form the dictionary
d = {}

n = int(input("Enter the number of countries: "))

for i in range(0, n):
    country = input("Enter the name of Country: ")
    capital = input('Enter the capital name: ')

    d[country] = capital

print(d)
e = input("Enter the Country: ")
for i in d:
    if i == e:
        print("The name of the Capital of", e, "is", d[i])
