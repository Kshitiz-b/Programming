s1 = ['', '', '', '', '', '', '', '', '', '']
s2 = ['', '', '', '', '', '']
s3 = ['', '', '', '']
s4 = ['', '', '', '', '', '', '', '']
for i in range(len(s1)):
    x = input()
    s1.modify(x)
print(s1)
for i in range(len(s2)):
    x = input()
    s2.append(x[i])
print(s2)
for i in range(len(s3)):
    x = input()
    s3.append(x[i])
print(s3)
for i in range(len(s4)):
    x = input()
    s4.append(x[i])
print(s4)
for i in range(len(s1)):
    l1 = []
    for j in range(len(s2)):
        if s1[i] == s2[j]:
            l1.append(s1[i])

for i in range(len(s3)):
    l2 = []
    for j in range(len(s4)):
        if s3[i] == s4[j]:
            l2.append(s3[i])
    print(l2)

