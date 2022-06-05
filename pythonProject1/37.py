l =[]

e = []

o = []

n = int(input("enter number of elements : "))

for x in range(n):

    x = int(input())

    l.append(x)

for j in range(len(l)):

    if l[j]%2 == 0:

        e.append(l[j])

    elif l[j]%2!=0:

        o.append(l[j])

print(e)

print(o)