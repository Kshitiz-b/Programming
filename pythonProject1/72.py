import re
x = input("Enter pan number ")
if re.match('[A-Z]{5}[0-9]{3}[A-Z]$', x):
    print("Valid")
else:
    print("Invalid")
