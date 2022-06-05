def freq(phrase):
    phrase = phrase.split()
    phrase.sort()
    str1 = []

    for i in phrase:
        if i not in str1:
            str1.append(i)

    for i in range(0, len(str1)):
        print(str1[i], ':', phrase.count(str1[i]))


phrase = input()
freq(phrase)
