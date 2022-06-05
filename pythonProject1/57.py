math = set()
phy = set()
chem = set()
cs = set()
m_M = int(input())
for i in range(0, m_M):
    val = input()
    math = math | {val}
m_P = int(input())
for i in range(0, m_P):
    val = input()
    phy = phy | {val}
m_C = int(input())
for i in range(0, m_C):
    val = input()
    chem = chem | {val}
m_CS = int(input())
for i in range(0, m_CS):
    val = input()
    cs = cs | {val}
failure = math | phy | chem | cs
print(len(failure))
