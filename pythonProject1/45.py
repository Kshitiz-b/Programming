M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
T = [[9, 8, 7], [6, 5, 4], [3, 2, 1]]
sum = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
for i in range(len(M)):
    for j in range(len(M[i])):
        sum[i][j] = M[i][j] + T[i][j]
print(sum)
