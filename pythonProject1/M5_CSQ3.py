import re

phrase = input()
word = input()

match = re.search(word, phrase)
if word in phrase:
    s = match.start()
    e = match.end()
    print('%d to %d' % \
          (s, e))
else:
    print("Not found")
