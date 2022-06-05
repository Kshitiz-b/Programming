word1 = input('')

leng = len(word1)
count = 0
for i in range(0, leng):
    for j in range(0, leng):
        if word1[i] == word1[j]:
            count += 1
if count == len(word1):
    print('GOOD')
else:
    print('BAD')
