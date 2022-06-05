m = int(input("Enter the row size: "))
n = int(input("Enter the column size: "))
M1 = []
for i in range(m):
    L1 = []
    for j in range(n):
        L1.append(int(input()))
    M1.append(L1)
print(M1)
M2 = []
for i in range(m):
    L2 = []
    for j in range(n):
        L2.append(int(input()))
    M2.append(L2)
print(M2)
M3 = []
for i in range(m):
    L3 = []
    for j in range(n):
        L3.append(M1[i][j] + M2[i][j])
    M3.append(L3)
for i in range(m):
    for j in range(n):
        print(M3[i][j], end='')
    print()
