num = int(input("Enter a number to find factorial: "))

factorial = 1
if num < 0:
    print("Factorial does not defined for negative integer")
elif num == 0:
    print("The factorial of 0 is 1")
else:
    while num > 0:
        factorial = factorial * num

        num = num - 1

    print("factorial of the given number is: ")
    print(factorial)
