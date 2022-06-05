n1 = int(input())
n2 = int(input())

for i in range(n1, n2):
    n = 0
    for j in range(1, i):
        if i % j == 0:
            n += 1
    if n <= 1:
        print(i, ',', end='')
