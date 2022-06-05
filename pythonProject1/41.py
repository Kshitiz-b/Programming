element = int(input("Enter no of elements: "))
L1 = []
for i in range(0, element):
    x = int(input())
    L1.append(x)
L2 = [0]
for j in L1:
    for k in L2:
        if j > k:
            L2 = [j]
print(L2)
