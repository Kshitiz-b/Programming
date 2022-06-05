direct = {}

n = int(input('Enter the no.of employees :'))

for i in range(n):

    num = []

    name = input('Enter employee name : ')

    ans = input('Do you want to enter more numbers (Y/N) :')

    while ans == 'Y':

        x = int(input('Enter mobile number : '))

        num.append(x)

        ans = input('Do you want to enter more numbers (Y/N) :')

    direct[name] = tuple(num)

print(direct)

empname = input('Enter the employee name whose number is to be displayed : ')

for j in direct:

    if empname in j:

        for k in range(len(direct[j])):

            print(direct[j][k])
