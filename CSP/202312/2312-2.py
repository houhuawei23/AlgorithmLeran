"""
10**3, 10**5, 10**10
预处理出 < sqrt(N) 的质数，作为待枚举的质因子
"""

# 预处理出前
MAXN = 10**5 + 10

primes = []

for i in range(2, MAXN):
    is_prime = True
    for j in primes:
        if i % j == 0:
            is_prime = False
            break
    if is_prime:
        primes.append(i)

# print(primes)
nums = len(primes)


def cal(n, k):
    res = 1
    for i in range(nums):
        p = primes[i]
        cnt = 0
        if p * p > n:
            break
        while n % p == 0:
            cnt = cnt + 1
            n = n // p
        if cnt >= k:
            res = res * p**cnt
            # print(p, cnt, res)
    # print(res)
    return res


q = int(input())
res_list = []
for i in range(q):
    n, k = map(int, input().split())
    res_list.append(cal(n, k))
    # print(n, k)

# print(res_list)
for res in res_list:
    print(res)