"""
背包问题
暴力枚举 70
    二进制表示 bin(k)[2:]
    字符串反转 s[::-1]
    字符串格式化？对齐，填充？
        %，format，f-string
动态规划？？
"""

n, x = map(int, input().split())
# aa = [0 for i in range(n)]
aa = []

for i in range(n):
    aa.append(int(input()))

mmin = float("inf")


def cal(k):
    sum = 0
    s = bin(k)[2:]
    s = s[::-1]
    # print(f"s: {s}")
    l = len(s)
    # print(f"l: {l}")
    for i in range(l):
        if s[i] == "1":
            sum += aa[i]
    # print(f"sum: {sum}")
    return sum


for i in range(1, 2**n):
    tmp = cal(i)
    if tmp < mmin and tmp >= x:
        mmin = tmp

print(mmin)
