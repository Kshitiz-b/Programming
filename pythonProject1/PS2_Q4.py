import math

n = int(input())
if n > 0:
    l = []
    min = 999
    for i in range(n):
        x = int(input())
        if x < 0:
            print("Invalid input")
        y = int(input())
        if y < 0:
            print("Invalid input")
        l.append((x, y))
    m = []

    for i in range(0, n - 1):
        for j in range(i + 1, n):
            x1, y1 = l[i]
            x2, y2 = l[j]
            d = math.sqrt(((x2 - x1) ** 2) + ((y2 - y1) ** 2))
            if d < min:
                min = d

                m.append((x1, y1))
                m.append((x2, y2))
            elif d == min:
                m.append((x1, y1))
                m.append((x2, y2))
    for i in m:
        print(i)
else:
    print("Invalid input")

