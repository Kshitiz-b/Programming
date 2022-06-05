D = {}

n = int(input())

ls = []

for i in range(0, n):
    x = input()
    y = input()
    ls.append((x, y))

for i in range(0, n-1):
    for j in range(0, n-1):
        if (ls[j] > ls[j + 1]):
            ls[j], ls[j + 1] = ls[j + 1], ls[j]
            print(ls)
