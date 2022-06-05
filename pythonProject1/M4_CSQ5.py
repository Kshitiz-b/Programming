n = int(input())
l = []
for i in range(1, n+1):
    student = {}

    M1 = int(input())
    student['M1'] = M1

    M2 = int(input())
    student['M2'] = M2

    M3 = int(input())
    student['M3'] = M3
    l.append(student)

M1_fail = 0
M2_fail = 0
M3_fail = 0
count = 0
for i in range(len(l)):
    if l[i]['M1'] < 50:
        M1_fail += 1
    if l[i]['M2'] < 50:
        M2_fail += 1
    if l[i]['M3'] < 50:
        M3_fail += 1
dict_fail = {}
dict_fail['M1'] = M1_fail
dict_fail['M2'] = M2_fail
dict_fail['M3'] = M3_fail
print(dict_fail)


for i in range(len(l)):
    if l[i]['M1'] < 50 or l[i]['M2'] < 50 or l[i]['M3'] < 50:
        count += 1
print(count)
