# Search the list
def search(l, x):
    for i in range(len(l)):
        if l[i] == x:
            print("It is present")
            break
    else:
        print("Not present")


l1 = list(input("Enter a list: "))
print(l1)
b = input("Enter the element to be searched: ")
search(l1, b)
