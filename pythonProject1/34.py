n = int(input("Enter the number of elements: "))
L = []
for x in range(n):
    e = int(input())
    L.append(e)

for i in range(len(L)):
    if L[i] % 2 == 0:
        print("Even number is:", L[i])
for i in range(len(L)):
    if L[i] % 2 != 0:
        print("Odd number is:", L[i])
