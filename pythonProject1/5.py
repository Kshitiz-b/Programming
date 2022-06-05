x = float(input("Enter first number: "))

y = float(input("Enter second number: "))

z = float(input("Enter third number: "))

if x>y and x>z:
    print("First number is the greatest",x)
elif y>z and y>x:
    print("Second number is the greatest",y)
else:
    print("Third number is the greatest",z)
