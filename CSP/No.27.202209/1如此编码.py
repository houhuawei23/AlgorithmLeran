"""
Lemma:
if (a%c + b%c) < c, then (a + b) // c == a // c + b // c

let mi:
m1 = b1 + a1*b2 + a1*a2*b3 + a1*a2*a3*b4 +... + a1*a2*...*an-1*bn
m2 =  0 +    b2 +    a2*b3 +    a2*a3*b4 +... +    a2*...*an-1*bn
m3 =  0 +     0 +       b3 +       a3*b4 +... +       a3*...*an-1*bn

let aa[i][j] = ai * ai+1 * ... * aj-1 * aj, a0 = 1,
    if i > j: aa[i][j] = 1

then:
mi = Sum[j=i to n] (aa[i][j-1] * bj)

m1 = Sum[j=1 to n] (aa[1][j-1] * bj)
   = aa[1][0]*b1 + aa[1][1]*b2 + ... + aa[1][n-1]*bn
   = b1 + a1*b2 + a1*a2*b3 + a1*a2*a3*b4 + ... + a1*a2*...*an-1*bn

m2 = Sum[j=2 to n] (aa[2][j-1] * bj)
   = aa[2][1]*b2 + aa[2][2]*b3 + ... + aa[2][n-1]*bn
   =  0 +    b2 +    a2*b3 +    a2*a3*b4 + ... +    a2*...*an-1*bn

m3 = Sum[j=3 to n] (aa[3][j-1] * bj)
   = aa[3][2]*b3 + aa[3][3]*b4 + ... + aa[3][n-1]*bn
   =  0 +     0 +       b3 +       a3*b4 + ... +       a3*...*an-1*bn

has:
1) bi = mi % ai
2) mi+1 = mi // ai

1) is obviously true, as 0 <= bi < ai.
2) proof:
mi = bi + ai*(mi-1)
bi % ai = bi, ai*(mi-1) % ai = 0, we have:
(bi % ai) + (ai*(mi-1) % ai) < ai
with Lemma, we have:
(bi + ai*(mi-1)) // ai == (bi // ai) + (ai*(mi-1) // ai) == 0 + (mi-1) == mi-1
so:
mi+1 = mi // ai

then give the algorithm:
m1 = m
for i from 1 to n:
    bi = mi % ai
    mi+1 = mi // ai

which is implemented by solve() function.
"""


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))

    for i in range(n):
        b = m % a[i]
        m = m // a[i]
        print(b, end=" ")


def solve2():
    n, m = map(int, input().split())
    a = [0]
    a += list(map(int, input().split()))
    b = [0 for i in range(n + 1)]
    c = [0 for i in range(n + 1)]
    c[0] = 1
    tmp = 0
    for i in range(1, n + 1):
        c[i] = a[i] * c[i - 1]
        b[i] = (m % c[i] - tmp) // c[i - 1]
        tmp += c[i - 1] * b[i]
    for i in range(1, n + 1):
        print(b[i], end=" ")


def solve3():
    n, m = map(int, input().split())
    a = [0]
    a += list(map(int, input().split()))
    c = 1
    nc = 1
    tmp = 0
    for i in range(1, n + 1):
        nc = a[i] * c
        b = (m % nc - tmp) // c
        tmp += c * b
        c = nc
        print(b, end=" ")


solve3()
