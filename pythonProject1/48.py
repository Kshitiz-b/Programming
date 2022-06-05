m = int(input("Enter the row size: "))
n = int(input("Enter the column size: "))
M1 = []
for i in range(m):
    L1 = []
    for j in range(n):
        L1.append(int(input()))
    M1.append(L1)
print("Matrix: ")
for i in range(m):
    for j in range(n):
        print(M1[i][j], end=' ')
    print()

M3 = []
print("Transpose of the Matrix is: ")
for i in range(m):
    L3 = []
    for j in range(n):
        L3.append(0)
    M3.append(L3)
for i in range(len(M1)):
    for j in range(len(M1[i])):
        M3[j][i] = M1[i][j]
for i in range(m):
    for j in range(n):
        print(M3[i][j], end=' ')
    print()
