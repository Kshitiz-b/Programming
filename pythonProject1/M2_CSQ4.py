f = float(input())
cel = (f-32)*5/9

dp = lambda x: x*(10**2)//1/(10**2)
print(dp(cel))
