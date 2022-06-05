l = []
n = int(input("enter number of elements : "))
for x in range(n):
    c = int(input())
    l.append(c)
f = int(input("Enter element to be searched for : "))
for j in range(len(l)):
    if l[j] == f:
        print("Element is present")
        break
else:
    print("Not Present")
