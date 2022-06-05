import re


def vowels(phrase):
    return re.findall(r'\b[aeiouAEIOU]\w+', phrase)


phrase = input("input= ")
words = vowels(phrase)
print("output=",words[0])
i = 1
while i < len(words):
    print(words[i])
    i = i + 1
