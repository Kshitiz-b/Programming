n = int(input())
m = int(input())
main_list = []
for i in range(n):
    temp = []
    for k in range(m):
        l = input()
        l = l.split()
        for j in range(len(l)):
            if l[j].isnumeric():
                [j] = int(l[j])
            elif l[j].isalpha():
                l[j] = str(l[j])
            elif '.' in l[j]:
                l[j] = float(l[j])
                temp.append(l[j])
            if len(temp) == m:
                main_list.append(temp)
        break
index = int(input())
value = input()
if value.isnumeric():
    value = int(value)
elif value.isalpha():
    value = str(value)
