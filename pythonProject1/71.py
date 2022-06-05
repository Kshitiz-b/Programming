import re
n = input("Enter VIT Registration number : ")
if re.match('[0-9][0-9][A-Z][A-Z][A-Z][0-9][0-9][0-9][0-9]$', n):
    print("Valid")
else:
    print("Invalid")
