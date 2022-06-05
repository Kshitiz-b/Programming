l = []

p = []

n = int(input("enter number of elements : "))

for x in range(n):

    x = int(input())

    l.append(x)

for j in range(len(l)):

    c = l.count(l[j])

    if c > 1:

        if l[j] not in p:

            p.append(l[j])

print(p)
