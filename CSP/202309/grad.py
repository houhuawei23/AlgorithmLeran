"""
使用栈计算后缀表达式的值
栈中保存的是 该“项”的值 + 该项的偏导数
因为递归地计算偏导数时，会用到 当前项的值 + 当前项的偏导数的值
!!递归计算
"""


MOD = int(1e9 + 7)

n, m = map(int, input().split())

# ['x1', 'x1', 'x1', '*', 'x2', '+', '*']
f = input().split()

# qs = []
ans = []


def main():
    for i in range(m):
        # qs.append()
        q = tuple(map(int, input().split()))
        ans.append(cal_alpha(q))

    for i in range(m):
        print(ans[i])


def cal_alpha(q):
    xid = q[0]
    x = q[xid]
    xstr = f"x{xid}"
    stack = []  # (a(x), a'(x))

    for e in f:
        if e in ["+", "-", "*"]:
            term2 = stack.pop()
            term1 = stack.pop()

            if e == "*":
                a = (term1[0] * term2[0]) % MOD
                ga = (term1[1] * term2[0] + term1[0] * term2[1]) % MOD
            elif e == "-":
                a = (term1[0] - term2[0]) % MOD
                ga = (term1[1] - term2[1]) % MOD
            elif e == "+":
                a = (term1[0] + term2[0]) % MOD
                ga = (term1[1] + term2[1]) % MOD
            stack.append((a, ga))
            continue
        # not in + - *
        if e == xstr:
            # 如果是变量 xstr
            stack.append((x, 1))
        elif e[0] == "x":
            # 如果是其他变量 x56
            xj = q[int(e[1:])]
            stack.append((xj, 0))
        else:  # 是常数
            stack.append((int(e), 0))
    return stack.pop()[1]


main()
# print(MOD)
# print(f)
