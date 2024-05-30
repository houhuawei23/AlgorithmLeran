#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int MAXM = 1e4 + 5;

int a[MAXN];
int dp[MAXN][MAXM];
int N, M;


void print_dp() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

/*

dp[i][j]
从前 i 个物品中选则, 总价格恰好==j的方案个数
dp[0][j]: 0
dp[i][0]: 1, 什么也不选, 算一种方案
*/

int main() {
    cin >> N >> M;
    /* init dp */
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        for (int j = 1; j <= M; j++) {
            if (j < a[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
            }
        }
    }
    cout << dp[N][M];
}