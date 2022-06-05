n1 = int(input())
n2 = int(input())
m = 0
n = 0
for i in range(1, n1):
    if n1 % i == 0:
        m = m + i
for i in range(1, n2):
    if n2 % i == 0:
        n = n + i
if m == n:
    print('amicable')
else:
    print('not amicable')
