import re

n = int(input("Enter number of students: "))
L = []
for i in range(0, n):
    x = input("Enter Registration number : ")
    L1 = []
    if re.match('[0-9]{2}[A-Z]{3}[0-9]{4}$', x):
        L1.append(x)

    else:
        print("Not a VITIAN")
    L.append(L1)
print(L)
