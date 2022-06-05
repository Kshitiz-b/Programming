# To generate fibonacci sequence
def fib(x):
    if x == 0:
        return 0
    elif x <= 1:
        return x
    else:
        return fib(x-1)+fib(x-2)


num = int(input("Enter the number: "))
for i in range(num):
    print("The Fibonacci Sequence is: ", fib(i))
