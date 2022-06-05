# To check if it is a palindrome
def palindrome(x):
    if x[::-1] == x:
        return "True"
    else:
        return "False"


s = input()
print(palindrome(s))
