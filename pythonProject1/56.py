S1 = {1, 3, 4}
S2 = {2, 3, 5}
S2.add((1, 2, 3))
print(S2)
print((1, 2, 3) in S2)
S3 = S2.union(S1)
print(S3)
S3.remove(3)
print(S3)
S3.pop()
print(S3)
cities = frozenset(["Frankfurt", "Basel"])
print(cities)
