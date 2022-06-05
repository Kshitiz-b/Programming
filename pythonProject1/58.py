s1 = set()
s2 = set()
s3 = set()
n1 = int(input("number of elements in set1"))
for i in range(n1):
    x = int(input())
    s1.add(x)
n2 = int(input("number of elements in set2"))
for i in range(n2):
    x = int(input())
    s2.add(x)
n3 = int(input("number of elements in set3"))
for i in range(n3):
    x = int(input())
    s3.add(x)
print(s1)
print(s2)
print(s3)
s4 = s1 & s2 & s3
if s4 == set():
    print("there are no common elements")
else:
    print("the set with common elements:", s4)
