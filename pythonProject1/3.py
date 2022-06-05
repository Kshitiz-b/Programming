# computer cost
x = float(input("Enter the cost of one computer: "))
x1 = int(input("Enter the number of computers: "))

# furniture cost
y = float(input("Enter the cost of one table: "))
y1 = int(input("Enter the number of tables: "))

z = float(input("Enter the cost of one chair: "))
z1 = int(input("Enter the number of chairs: "))

# labour cost
a = float(input("Enter the number of hours worked: "))
a1 = float(input("Enter the wages per hour: "))

b = x*x1 + (y*y1 + z*z1) +a*a1
print("Cost of setting the lab: ", b)