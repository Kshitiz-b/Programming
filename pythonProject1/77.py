string = input("Enter a string : ")

substring = input("Enter a substring : ")

string = string.split()

if substring not in string:

    print("Substring not found")

else:
    count = string.count(substring)
    print(substring, "occurs in the string", " ".join(string), ",", count, "times")
    for i in range(len(string)):

        if string[i] == substring:

            string[i] = ''

    print("The modified string is : ", " ".join(string))
