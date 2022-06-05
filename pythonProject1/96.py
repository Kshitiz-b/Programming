# Global variable 'init'
init = 1


# Define 'plus()' function to accept a variable number of arguments
def plus(*args):
    # Local variable "sum"
    sum = 0
    for i in args:
        sum += i
    return sum


# Access the global variable
print("This is the initialized value " + str(init))
x = plus(10, 20, 30, 40)

# (Try to) access the local variable
print("This is the sum " + str(sum))
