a1 = input("")
a2 = input("")
SearchPosition = int(input(""))
if a2 not in a1:
    print("NotAvailable")
elif a1 == a2:
    FoundPosition = -(SearchPosition-1)
    print(FoundPosition)
else:
    fl = a2[0]
    FoundPosition = a1.index(fl) - SearchPosition
    print(FoundPosition)
