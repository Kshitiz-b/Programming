x = int(input("Enter number of rows:"))
y = int(input("Enter number of columns:"))
M1 = []
print("Enter the elements of Matrix 1")
for i in range(x):
    L = []
    for j in range(y):
        k = int(input())
        L.append(k)
        M1.append(L)

print("Enter the elements of Matrix 2")
M2 = []
for i in range(x):
    L = []
    for j in range(y):
        k = int(input())
        L.append(k)
        M2.append(L)
s = 0
P = []
for i in range(x):
    for j in range(y):
        p = M1[i][j] * M2[j][i]
        s = s+p

for q in range(x):
    L = []
    for w in range(y):
        L.append(s)
        P.append(L)
s = 0

print("Matrix 1")
for i in range(x):
    for j in range(y):
        print(M1[i][j], end=' ')
    print()
print("Matrix 2")
for i in range(x):
    for j in range(y):
        print(M2[i][j], end=' ')
    print()
print("After Multiplication")
for i in range(x):
    for j in range(y):
        print(P[i][j], end=' ')
    print()
