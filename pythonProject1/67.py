n = input("Enter VIT Registration Number : ")

if len(n) != 9:

    print("Invalid")

else:

    if n[0].isnumeric() == True and n[1].isnumeric() == True:

        if n[2:5].isalpha() == True and n[2:5].isupper() == True:

            if n[5:9].isnumeric() == True:

                print("Valid Registration number")

            else:

                print("Invalid")

        else:

            print("Invalid")

    else:

        print("Invalid")
