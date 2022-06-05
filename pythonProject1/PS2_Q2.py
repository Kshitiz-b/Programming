l1 = int(input())
l2 = int(input())
l3 = int(input())

if l1 < 400 or l2 < 400 or l3 < 400:
    print("Number of litres must be above 400")
else:
    if l1 > l2:
        smaller = l2
    else:
        smaller = l1
    for i in range(2, smaller+1):
        if (l1 % i == 0) and (l2 % i == 0):
            hcf = i
            n = int((l1 / hcf) + (l2 / hcf) + (l3 / hcf))
            print(n)