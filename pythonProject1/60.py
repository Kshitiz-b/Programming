v = ['a', 'e', 'i', 'o', 'u']
n = input('Enter a string: ')
count = 0
for i in range(len(n)):
    if n[i] in v:
        count += 1
print(count)
