def plus(*args):
    sum = 0
    for i in args:
        sum += i
    return sum


print(plus(1, 2, 3, 4, 5))
print(plus(1, 2, 3, 4))
print(plus(1, 2, 3))
print(plus(1, 2))

