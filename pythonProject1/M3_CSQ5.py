number = int(input())
total_sum = 0
step = 1

condition = True

while condition:

    while number:
        total_sum += number % 10
        number //= 10
    if total_sum <= 9:
        print(total_sum)
    number = total_sum
    total_sum = 0
    step += 1
    condition = number > 9
