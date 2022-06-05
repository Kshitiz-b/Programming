import re
n = input("Enter a Phone number : ")

if len(n) != 10:

    print("Invalid")

else:

    if re.match('[6-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]', n):

        print("Valid")

    else:

        print("Invalid")
