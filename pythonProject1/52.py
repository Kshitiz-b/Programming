# Dictionary
labreading = {}
n = int(input("Enter the number of tests: "))
for i in range(0, n):
    testname = input("Enter the Testname:")
    minvalue = int(input("Enter min value:"))
    maxvalue = int(input("Enter max value:"))
    labreading[testname] = (minvalue, maxvalue)
print(labreading)
checktest = input("Enter the test to be done")
obs = int(input("Enter the observed value"))
for i in labreading:
    if j == checktest:
        if obs < labreading[j][0] or obs < labreading[j][1]:
            print("Abnormal Condition")
        else:
            print("Normal Condition")