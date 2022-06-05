n = input("Enter a number: ")
s = len(n)
if s == 10 and n.isnumeric():
    print("valid number")

    if n[0:1] == '6' or n[0:1] == '7' or n[0:1] == '8' or n[0:1] == '9':
        print("Indian Number")
    else:
        print("Not a Indian Number")

else:
    print("invalid")
