n = int(input("Enter a number:"))
print("Prime Nos.")
for i in range(2, n+1):
    if i > 0:
        for j in range(2, i):
            if i % j == 0:
                break
        else:
            print(i, end=' ')
print()

print("Composite Nos.")
for i in range(2, n+1):
    if i > 0:
        for k in range(2, i):
            if i % k != 0:
                break
            else:
                print(i, end=' ')