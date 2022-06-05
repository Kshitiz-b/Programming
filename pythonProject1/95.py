def palindrome(s):
    reverse = s[::-1]
    if reverse == s:
        return print("The string is palindrome")
    else:
        return print("The string is not palindrome")


string = input("Enter a string : ")
palindrome(string)
