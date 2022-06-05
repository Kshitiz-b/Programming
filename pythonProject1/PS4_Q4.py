n1 = int(input())
n2 = int(input())
m1 = []
x = 0
y = 0

for i in range(n1):
    m2 = []
    for j in range(n2):
        m2.append(int(input()))
    m1.append(m2)
for i in range(n1):
    x = x+m1[i][i]
    y = y+m1[i][n1-(i+1)]
d = x-y
print(abs(d))
