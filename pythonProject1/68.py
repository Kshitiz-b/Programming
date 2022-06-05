n = input("Enter a string : ")
if len(n) != 10:
    print("invalid")
else:
    if n[0:5].isalpha() is True and n[0:5].isupper() is True:
        if n[5:9].isnumeric() is True:
            if n[9].isalpha() is True and n[9].isupper() is True:
                print("Valid Pan Number")
            else:
                print("Invalid")
        else:
            print("Invalid")
    else:
        print("Invalid")
