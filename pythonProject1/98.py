# Recursive Function
# Program to find factorial of a number

def calc_factorial(x):
    """This is a recursive function
    to find the factorial of an integer"""

    if x == 1:
        return 1    # Stopping condition for recursive function
    else:
        return x*calc_factorial(x-1)    # function calls itself ("calc_factorial(x-1)") i.e recursion


num = int(input("Enter the number: "))
print("The Factorial of", num, "is", calc_factorial(num))
