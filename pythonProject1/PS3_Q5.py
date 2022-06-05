s1 = input()
s2 = input()
x = s1.split()
y = s2.split()
m = x[len(x)-1]
n = y[0]
if (m.lower()) == (n.lower()):
    print('Pass')
else:
    print('Stop')
