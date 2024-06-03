/*
Multi Bag.
https://www.acwing.com/problem/content/4/

0 < N, V <= 100
0 < vi,wi,si <= 100

O(N*V*K) = 1e(2+2+2) = 1e6
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int MAXV = 105;

int N, V;
int v, w, s;

int dp[MAXN][MAXV];

void solveBase() {
    for (int i = 1; i <= N; i++) {
        cin >> v >> w >> s;
        for (int j = 1; j <= V; j++) {
            for (int k = 0; k <= s && j >= k * v; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v] + k * w);
            }
        }
    }
}

int main() {
    cin >> N >> V;
    solveBase();
    cout << dp[N][V];
}

/*
输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/