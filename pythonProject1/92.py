def ul(l):
    unique_list = []
    for i in range(len(l)):
        if l[i] not in unique_list:
            unique_list.append(l[i])
    return print("Unique list is : ", unique_list)


n = int(input("Enter number of elements : "))
p = []
for i in range(n):
    item = input("Enter list elements : ")
    p.append(item)
ul(p)
