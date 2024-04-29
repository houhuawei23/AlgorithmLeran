# import numpy as np

MAXN = 1005
MAXV = 1005

# dp = np.zeros((MAXN, MAXV), int)
dp = [[0] * (MAXV) for _ in range(MAXN)]
N, V = map(int, input().strip().split())

for i in range(1, N + 1):
    v, w = map(int, input().strip().split())
    for j in range(1, V + 1):
        dp[i][j] = dp[i - 1][j]
        if j >= v:
            dp[i][j] = max(dp[i][j], dp[i - 1][j - v] + w)
# print(N, V)
print(dp[N][V])
