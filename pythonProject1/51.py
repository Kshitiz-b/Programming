# Tuple
t = (2, 5, 1, 8)

t1 = (1, 3, 4, 6)
t2 = t + t1
print(t2)
t3 = sorted(t2)  # gets converted into list
print(t3)
t4 = tuple(t3)
print(t4)
for i in t3:
    print(i)
