import re
import sys
n = int(input("Enter number of students : "))
l = []
for i in range(n):
    tstring =''
    regno = input("Enter VIT register number : ")
    name = input("Enter student name : ")
    if re.match("^[0-9]{2}[a-zA-Z]{3}[0-9]{4}$", regno):
        tstring = tstring + regno + " " + name
        l.append(tstring)
    else:
        print("Invalid Input")
        sys.exit()
print(l)
string2 = input("Enter a string : ")
for i in range(len(l)):
    string3 = ''
    for j in string2:
        count = l[i].count(j)
        string3 = string3 + ' ' + j + ' ' + '-' + ' ' + str(count)
    print(string3)
for i in string2:
    for j in range(len(l)):
        l[j] = l[j].replace(i,"")
print(l)