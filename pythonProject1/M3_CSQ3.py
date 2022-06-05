mark = float(input())
if mark == 0:
    print("Enter the appropriate mark")

else:
    class_type = str(input())
    bonus = 0

    if mark >= 80 and class_type == 'T':
        bonus = bonus + (mark*8)/100
        Result = bonus + mark
        print(Result)
    elif mark >= 80 and class_type == 'L':
        bonus = bonus + (mark*6)/100
        Result = bonus + mark
        print(Result)
    elif mark >= 60 and class_type == 'T':
        bonus = bonus + (mark*6)/100
        Result = bonus + mark
        print(Result)
    elif mark >= 60 and class_type == 'L':
        bonus = bonus + (mark*4)/100
        Result = bonus + mark
        print(Result)
    elif mark >= 40 and class_type == 'T':
        bonus = bonus + (mark*4)/100
        Result = bonus + mark
        print(Result)
    elif mark >= 40 and class_type == 'L':
        bonus = bonus + (mark*2)/100
        Result = bonus + mark
        print(Result)
    else:
        print(mark)
