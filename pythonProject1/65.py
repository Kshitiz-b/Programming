n = input("Enter a mobile number: ")
s = len(n)
if s == 10 and n.isnumeric():
    print("valid number")
else:
    print("invalid")
