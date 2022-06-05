ls = [100, 90, 50, 40, 10, 9, 5, 4, 1]
dict = {1:"I", 4:"IV", 5:"V", 9:"IX", 10:"X", 40:"XL", 50:"L", 90:"XC", 100:"C"}
ls2 = []

def func(no, res):
    for i in range(0, len(ls)):
        if no in ls:
            res = dict[no]
            rem = 0
            break
        if ls[i] < no:
            quo = no//ls[i]
            rem = no%ls[i]
            res = res+dict[ls[i]]*quo
            break
    ls2.append(res)
    if rem == 0:
        pass
    else:
        func(rem, "")


num = int(input())
func(num, "")
print("".join(ls2))
