n = input("Enter a string : ")

n = n.split()

for i in range(len(n)):

    n[i] = n[i].capitalize()

s = ' '.join(n)

print(s)
