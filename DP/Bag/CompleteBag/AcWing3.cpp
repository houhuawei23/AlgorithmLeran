#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MAXV = 1e3 + 5;

int N, V;
int v, w;

int dp[MAXN][MAXV];

void solveBase() {
    for (int i = 1; i <= N; i++) {
        cin >> v >> w;
        for (int j = 1; j <= V; j++) {
            for (int k = 0; j >= k * v; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v] + k * w);
            }
        }
    }
}

void solveOpt() {
    for (int i = 1; i <= N; i++) {
        cin >> v >> w;
        for (int j = 1; j <= V; j++) {
            if (j < v)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - v] + w);
        }
    }
}
int main() {
    cin >> N >> V;
    solveOpt();
    cout << dp[N][V];
}

/*
4 5
1 2
2 4
3 4
4 5

10
*/