/*
https://www.luogu.com.cn/problem/P1049
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 35;
const int MAXV = 2e4 + 10;

int V, n;
// int v[MAXN];
int dp[MAXN][MAXV];

int main() {
    cin >> V >> n;
    int v;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v] + v);
        }
    }
    cout << V - dp[n][V];
}