mval = 0
dict = {}


def entry():
    for i in range(0, 3):
        name = input()
        scr = input()
        dict[scr] = name
    sc = list(dict.keys())
    sc.sort()
    return sc


def mean(sc):
    ad = 0
    for i in range(0, len(sc)):
        ad = ad + int(sc[i])
    mean = int(ad / int(len(sc)))
    return mean


def output(mean, sc):
    for j in range(0, len(sc)):
        if mean == int(sc[j]):
            mval = j
        else:
            mval = 1
    mname = dict[sc[mval]]
    before = dict[sc[mval - 1]]
    after = dict[sc[mval + 1]]
    print(mname)
    print(after)
    print(before)


sc = entry()
m = mean(sc)
output(m, sc)
