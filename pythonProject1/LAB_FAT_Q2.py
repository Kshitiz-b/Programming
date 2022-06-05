upc = input()
sum = 0
m = 0
n = 0
check = 0
l = len(upc)
if l > 12 or l < 12:
    print("Cannot be processed")
else:
    for i in range(1, 12, 2):
        m = m + int(upc[i - 1])
    m = m * 3

    for i in range(2, 11, 2):
        n = n + int(upc[i - 1])
    sum = m + n
    sum1 = str(sum)
    if sum1[-1] == 0:
        check = sum
    else:
        check = 10 - int(sum1[-1])
    if check == int(upc[-1]):
        print("Validated")
    else:
        print("Error in barcode")
