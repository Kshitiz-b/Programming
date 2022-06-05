while True:
    x = int(input("Enter a number: "))
    if x % 2 == 0:
        print("The number is even")
        continue
    else:
        print(x, "is odd")
