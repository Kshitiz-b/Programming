M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
T = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
for i in range(len(M)):
    for j in range(len(M[i])):
        T[j][i] = M[i][j]
print(T)
