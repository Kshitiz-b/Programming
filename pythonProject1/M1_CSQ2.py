n = int(input())
liters = 0
ml = 0
for i in range(0, n):
    n1 = input()
    n1 = n1.strip()
    liters = liters+int(n1[0])
    ml = ml+int(n1[1:])
    if ml >= 1000:
        liters += 1
        ml = ml-1000
print(liters, "(in liters)")
print(ml, "(in ml)")


