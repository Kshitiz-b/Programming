def sort(l):
    for i in range(len(l)-1):
        for j in range(len(l)-i-1):
            if l[j] > l[j+1]:
                l[j], l[j+1] = l[j+1], l[j]
        print(l)


n = int(input("enter number of elements : "))
p = []
for i in range(n):
    item = int(input("Enter the elements : "))
    p.append(item)
sort(p)

