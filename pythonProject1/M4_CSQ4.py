n = int(input())
category = []

for i in range(n):
    item = int(input())

    cat = input()
    cost = 0

    for j in range(item // 2):
        comp = input()
        comp_cost = int(input())
        cost += comp_cost
    category.append((cat, cost))

category = tuple(category)
print(category)