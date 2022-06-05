def search(l, n):
    for i in range(len(l)):
        if l[i] == n:
            print("The Element is found")
            break
    else:
        print("Not Found")


a = list(input("enter a list : "))
print(a)
b = input("enter element to be searched : ")
search(a, b)
