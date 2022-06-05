def SI(p=100, r=10, t=1):
    si = (p*r*t)/100
    return print("The simple interest is : ", si)


principal = float(input("Enter the principal amount : "))
rate = float(input("Enter rate of interest : "))
time = float(input("Enter time period(in years) : "))
SI(principal, rate, time)
SI(principal, rate)
SI(principal)
SI()
