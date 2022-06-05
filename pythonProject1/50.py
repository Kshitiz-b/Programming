m1 = int(input("Enter the row size: "))
n1 = int(input("Enter the column size: "))
M1 = []
print("Enter Matrix 1")
for i in range(m1):
    L1 = []
    for j in range(n1):
        L1.append(int(input()))
    M1.append(L1)
print("Matrix 1: ")
for i in range(m1):
    for j in range(n1):
        print(M1[i][j], end=' ')
    print()

m2 = int(input("Enter the row size: "))
n2 = int(input("Enter the column size: "))
M2 = []
print("Enter Matrix 2")
for i in range(m2):
    L2 = []
    for j in range(n2):
        L2.append(int(input()))
    M2.append(L2)
print("Matrix 2: ")
for i in range(m2):
    for j in range(n2):
        print(M2[i][j], end=' ')
    print()

if n1 != m2:
    print("Multiplication is not possible")
else:
    print("Matrix Multiplication: ")
    M3 = []
    for i in range(m1):
        L1 = []
        for j in range(n2):
            L1.append(0)
        M3.append(L1)
    for i in range(len(M1)):
        for j in range(len(M2[i])):
            for k in range(len(M3)):
                M3[i][j] = M3[i][j] + M1[i][k] * M2[k][j]
    for i in range(m1):
        for j in range(n2):
            print(M3[i][j], end=' ')
        print()
