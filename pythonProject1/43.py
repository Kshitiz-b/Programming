# Sorting
n = int(input("Enter the number of elements: "))
l = []
print("Enter the elements: ")
i = 0
for i in range(n):
    x = int(input())
    l.append(x)
print(l)
for i in range(0, n-1):
    for j in range(n-1):
        if (l[j] > l[j+1]):
            l[j], l[j+1] = l[j+1], l[j]
    print(l)
