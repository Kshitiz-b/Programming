l = []
n = int(input())
for i in range(0, n):
    x = int(input())
    l.append(x)
for j in range(len(l)):
    for k in range(j + 1, len(l)):
        if l[j] > l[k]:
            max = l[j]
        else:
            max = l[k]
print(max)
