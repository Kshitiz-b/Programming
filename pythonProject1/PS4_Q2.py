def matrix(order):
    m_1 = []
    for x in range(order):
        m_2 = []
        for y in range(order):
            i = int(input())
            m_2.append(i)
        m_1.append(m_2)
    c = 0
    d = 0
    for x in range(order):
        for y in range(order):
            if x == y:
                if m_1[x][y] == 1:
                    c = c+1
            if m_1[x][y] == 0:
                e = 0
            else:
                d = d+1
    if c == order & d == 0:
        return 'Identity matrix'
    else:
        return 'Not an identity matrix'


a = matrix(int(input()))
print(a)
