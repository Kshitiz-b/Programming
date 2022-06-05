l = []
n = int(input())

for i in range(0, n):
    i = int(input())
    l.append(i)
print("The list is: ", l)
l1 = []

for j in l:
    c = l.count(j)
    if c % 2 != 0:
        if j not in l1:
            l1.append(j)
    else:
        pass
print(l1)




