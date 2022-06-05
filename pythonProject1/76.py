import re
d = {}
n = int(input("enter number of students "))
for i in range(n):
    name = input("enter name of the student ")
    x = input("enter registration number ")
    branch = input("enter branch ")
    if re.match("[0-9]{2}[a-zA-Z]{3}[0-9]{4}$", x):
        d[x] = (name, branch)
print(d)
