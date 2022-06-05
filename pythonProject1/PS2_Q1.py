N = int(input())

for i in range(1, N):
    Sum = 0
    for n in range(1, i - 1):
        if i % n == 0:
            Sum = Sum + n

    if Sum == i:
        print(i)
