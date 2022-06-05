def getMiddleSumIfExists(lst):
    i = 0
    while(i < len(lst) and sum(lst[i + 1:]) !=sum (lst[:i])):
        i += 1
    if i == 0:
        return 0
    return i
if __name__=="__main__":
    N = int(input())
    nums = []
    for i in range(N):
        nums.append(float(input()))
    ind = getMiddleSumIfExists(nums)
    if ind == 0:
        print("No such index exists")
    else:
        print(ind)
