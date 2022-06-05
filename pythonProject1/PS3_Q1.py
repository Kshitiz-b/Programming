def max_rec(x, y):
    a = 0
    for j in range(x):
        b = y[j]
        if b >= a:
            a = b
    return a


n = int(input())
L = []
for i in range(n):
    L.append(int(input()))
print(max_rec(n, L))
