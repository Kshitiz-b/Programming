d = {}
s = input('Enter a sentence: ')


print(s)
for i in s:
    q = s.count(i)
    d[i] = q

print(d)
