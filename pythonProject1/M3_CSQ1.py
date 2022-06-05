x = float(input())
IT = 0
if x > 1000000:
    IT += (4*x)/100
elif x > 500000:
    IT += (2*x)/100
else:
    IT += 0
print(int(IT))
