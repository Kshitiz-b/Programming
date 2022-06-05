x1 = int(input("Enter rows: "))
y1 = int(input("Enter columns: "))
M1 = []
print("Enter Matrix 1")
for i in range(x1):
    L1 = []
    for j in range(y1):
        L1.append(int(input()))
    M1.append(L1)
print("Matrix 1: ")
for i in range(x1):
    for j in range(y1):
        print(M1[i][j], end=' ')
    print()

x2 = int(input("Enter rows: "))
y2 = int(input("Enter columns: "))
M2 = []
print("Enter Matrix 2")
for i in range(x2):
    L2 = []
    for j in range(y2):
        L2.append(int(input()))
    M2.append(L2)
print("Matrix 2: ")
for i in range(x2):
    for j in range(y2):
        print(M2[i][j], end=' ')
    print()

if y1 != x2:
    print("Multiplication not possible, please enter correct matrix order.")
else:
    print("Matrix Multiplication: ")
    M3 = []
    for i in range(x1):
        L3 = []
        for j in range(y2):
            L3.append(0)
        M3.append(L3)
    for i in range(len(M1)):
        for j in range(len(M2[i])):
            for k in range(len(M3)):
                M3[i][j] = M3[i][j] + M1[i][k] * M2[k][j]
    for i in range(x1):
        for j in range(y2):
            print(M3[i][j], end=' ')
        print()
