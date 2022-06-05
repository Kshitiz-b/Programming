x = int(input())
NumbersArray = [1, 4, 5, 9, 10, 40, 50, 90]
RomanArray = ['I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'XC']
i = 7
while x != 0:
    y = x // NumbersArray[i]
    x %= NumbersArray[i]

    while y:
        print(RomanArray[i], end="")
        y -= 1
    i -= 1
