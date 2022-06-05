s1 = input()
s2 = input()
for i in s2:
    if i in s1:
        print(i, '-', s1.count(i))
for j in s2:
    s1 = s1.replace(j, '')
print(s1)
