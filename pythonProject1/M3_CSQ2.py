distance = float(input())

if distance <= 10:
    bill = distance * 15
    print(int(bill))
elif distance <= 90:
    bill_1 = 150+(distance-10) * 8
    print(int(bill_1))
elif distance > 90:
    bill_2 = 870+(distance-100) * 6
    print(int(bill_2))
