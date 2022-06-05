import re

phrase = input()


print(re.findall('[0-9][0-9]', phrase))

print(re.findall('[A-Z][a-z]*', phrase))
