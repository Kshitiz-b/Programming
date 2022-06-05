head = int(input())
leg = int(input())
if leg % 2 !=0 or head ==0 or head > leg:
    print('No solution')
else:
    m = int((leg + (-2*head))/2)
    n = int(head - m)
    print(m)
    print(n)
