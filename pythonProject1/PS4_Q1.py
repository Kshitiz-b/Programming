filename = input()
x = int(input())
D = {}
for i in range(x):
    reg_no = input()
    reg_no = reg_no.rstrip()
    print(reg_no)
    reg = reg_no[len(reg_no) - 9:]
    name = reg_no[:len(reg_no) - 9]
    D[reg] = name
    print(D)

for i in sorted(D.keys()):
    print(D[i], i)
