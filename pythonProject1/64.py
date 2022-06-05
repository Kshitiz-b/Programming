str1 = input("Enter string: ")
str2 = input("Enter a substring: ")

if str2 not in str1:
    print("Substring not available")
else:
    str3 = str2.upper()
    str1 = str1.replace(str2, str3)
    print(str1)
