n = int(input('Enter a number: '))

for i in range(1, n+1):
    for k in range(n-1, -1, -1):
        print('', end='')
    for j in range(1, i+1):
        print(j, end='')
print()
