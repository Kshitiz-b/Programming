x = int(input("enter a number: "))
num = 0
a = 0
b = 1
while x > 0:
    print(num)
    a = b
    b = num
    num = num+a
    x -= 1
