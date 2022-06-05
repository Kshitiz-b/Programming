str1 = input("Enter the sentence: ")
str1 = str1.lower()
print(str1)

str2 = str1.strip(" ?!") # removes spaces and symbols at the end
print(str2)

words = str2.split(" ")
print(words)

sortwords = sorted(words)
print(sortwords)

finalstr = " ".join(sortwords)
print(finalstr)
