x = float(input("Enter the CGPA: "))
if x <= 10:
    if x >= 9:
        print("Outstanding")
    elif x >= 8:
        print("Excellent")
    elif x >= 7:
        print("Good")
    elif x >= 6:
        print("average")
    elif x >= 5:
        print("Needs improvement")

else:
    print("Invalid Input")
