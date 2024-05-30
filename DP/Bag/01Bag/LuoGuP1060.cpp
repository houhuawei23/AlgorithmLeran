#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e4 + 10;
const int MAXM = 30;

int n, m;
int v, p;
int dp[MAXM][MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v >> p;
        int w = v * p;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v] + w);
            }
        }
    }
    cout << dp[m][n];
}