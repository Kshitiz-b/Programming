x = int(input("enter a number: "))

num = 0
t = x
while x > 0:
    a = x % 10
    num = num+a**3
    x = x//10
if num == t:
    print(num)
else:
    print("Not Armstrong")
