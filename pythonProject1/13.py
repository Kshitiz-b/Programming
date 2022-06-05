n = int(input("Enter a number: "))
count = 0
while n != 0:
    n = int(n/10)
    count = count + 1
print("Number of digits", count)
