n = input("Enter a string : ")

S = ""

for i in range(len(n)):
    if n[i].islower():
        S += n[i].upper()
    elif n[i].isupper():
        S += n[i].lower()
    else:
        S += n[i]

print(S)
