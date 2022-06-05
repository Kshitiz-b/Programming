def write():
    try:
        f = open("Questions.txt", 'x')
    except:
        f = open("Questions.txt", 'w')
    f.write("1. Who is the prime minister of India? \n A. Narendra Modi   B. Shivraj Patil")
    f.write("2. Who is the President of USA?\n A. Donald Trump     B. Joe Biden  ")
    f.close()

    try:
        f = open("Answers.txt", 'x')
    except:
        f = open("Answers.txt", 'w')
    f.write("1.A\n")
    f.write("2.B")
    f.close


def ask():
    f = open("Questions.txt", "r")
    x = f.readline()
    a = input()
    x = f.readline()
    b = input()
    return a, b
    f.close()


def check(a, b):
    count = 0
    f = open("Answers.txt", 'r')
    x = f.readline()
    if a.upper() == x[2]:
        count += 1
    x = f.readline()
    if b.upper() == x[2]:
        count += 1
    return count


write()
a, b = ask()
cnt = check(a, b)
scr = int((cnt / 2) * 100)
print(scr)
