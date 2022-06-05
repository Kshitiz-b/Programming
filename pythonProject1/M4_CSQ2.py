n = int(input())
lst = input().split()

l = []
for i in lst:
    if i == '+':
        l[-2] = l[-2] + l[-1]
        l.pop()
    elif i == '-':
        l[-2] = l[-2] - l[-1]
        l.pop()
    elif i == '*':
        l[-2] = l[-2] * l[-1]
        l.pop()
    elif i == '/':
        l[-2] = l[-2] / l[-1]
        l.pop()
    else:
        l.append(int(i))

print(int(l[0]))