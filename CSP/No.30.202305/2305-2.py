Q = []  # n, d
K = []  # n, d
V = []
W = []  #  n
RES = []  # n, d
n, d = map(int, input().split())

# read input

for i in range(n):
    Q.append(list(map(int, input().strip().split())))


for i in range(n):
    K.append(list(map(int, input().strip().split())))

for i in range(n):
    V.append(list(map(int, input().strip().split())))

W = list(map(int, input().strip().split()))

# print(Q)
# print(K)
# print(V)
# print(W)


def reverse(A):
    # [[1, 2], [3, 4], [5, 6]]
    # [[1, 3, 5], [2, 4, 6]]
    rownum = len(A)
    colnum = len(A[0])
    R = []
    for c in range(colnum):
        line = []
        for r in range(rownum):
            line.append(A[r][c])
        R.append(line)
    return R


# print(reverse(K))
def jucheng(A, B):
    shapeA = (len(A), len(A[0]))
    shapeB = (len(B), len(B[0]))

    if shapeA[1] != shapeB[0]:
        print("not right shape")
        print(shapeA, shapeB)
        return
    R = []
    for i in range(shapeA[0]):
        line = []
        for j in range(shapeB[1]):
            sum = 0
            for k in range(shapeA[1]):
                sum += A[i][k] * B[k][j]
            line.append(sum)
        R.append(line)
    return R


# print(jucheng(Q, reverse(Q)))


def dot(x, A):
    # vector x dot matrix A
    # x = [1, 2, 3]
    # A = [[1,2,3], [4, 5, 6], [7, 8, 9]]
    if len(x) != len(A):
        print("not right shape")
        return
    R = []
    for i in range(len(x)):
        xi = x[i]
        Ai = A[i]
        line = []
        for e in Ai:
            line.append(xi * e)
        R.append(line)
    return R


# x = [1, 2, 3]
# A = [[1, 2, 3], [1, 2, 3], [1, 2, 3]]
# print(dot(x, A))


RES = jucheng(dot(W, jucheng(Q, reverse(K))), V)

# print(RES)
for r in RES:
    for e in r:
        print(e, end=" ")
    print()