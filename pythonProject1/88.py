def add(a, b, c, d=0):
    return a+b+c+d


def mul(a, b, c, d=0):
    return a*b*c*d


x = int(input())
y = int(input())
u = int(input())
v = int(input())

print("Addition is", add(x, y, u, v))
print("Multiplication is", mul(x, y, u, v))
