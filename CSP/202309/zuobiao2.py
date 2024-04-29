"""
n,m 1000 80% pass
100000 20% timeout


"""

from math import sin, cos

n, m = map(int, input().split())

operations = []

for i in range(n):
    op, a = input().split()
    op = int(op)
    a = float(a)
    operations.append((op, a))
# print(operations)
qs = []
for i in range(m):
    q = tuple(map(int, input().split()))
    qs.append(q)

def cal(q):
    # q is a tuple of (i, j, x, y)
    # return x, y
    i, j, x, y = q
    for l in range(i-1, j):
        # print(f"l: {l}")
        op, a = operations[l]
        # print(f"op, a: ({op}, {a})")
        if op == 1:
            x = a * x
            y = a * y
        elif op == 2:
            x0, y0 = x, y
            x = x0 * cos(a) - y0 * sin(a)
            y = x0 * sin(a) + y0 * cos(a)
    return x, y

for i in range(m):
    x, y = cal(qs[i])
    print(x, y)


"""
10 1
2 0.59
2 4.956
1 0.997
1 1.364
1 1.242
1 0.82
2 2.824
1 0.716
2 0.178
2 4.094
8 8 159430 -511187
"""