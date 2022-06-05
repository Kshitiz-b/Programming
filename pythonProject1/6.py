x = int(input("Enter hour(s) spent browsing: "))
y = int(input("Enter minute(s) spent browsing: "))

amount = 0
if x>=7:
    print("Invalid Input")
elif x>=5:
    amount = 200
    x = x - 5
amount = amount + (x*50) + y
print(amount)



