import re
print("DD-MM-YYYY")
x = input("Enter a date: ")
if re.match('^(0[1-9]|[12][0-9]|3[01])\-(0[1-9]|1[012])\-(2[0-9]{3}$)', x):
    print("Valid")
else:
    print("Invalid")
