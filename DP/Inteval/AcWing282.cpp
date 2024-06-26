/*
Merge Stones. 石子合并
https://www.acwing.com/problem/content/284/
Interval DP.

两两合并, 找出总合并代价最小的方案, 输出最小代价.

 N <= 300
输入样例：
4
1 3 5 2
输出样例：
22
*/

#include <bits/stdc++.h>
using namespace std;

bool debug = false;

const int MAXN = 310;
const int INF = 1e8;
int N;

int stones[MAXN];
int presum[MAXN];

int dp[MAXN][MAXN];

void print() {
    cout << "stones: " << endl;
    for (int i = 0; i <= N; i++) {
        cout << stones[i] << " ";
    }
    cout << endl;
    cout << "presum: " << endl;
    for (int i = 0; i <= N; i++) {
        cout << presum[i] << " ";
    }
    cout << endl;
    cout << "dp: " << endl;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (dp[i][j] == INF) {
                cout << "i ";
            } else
                cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // cout << endl;
}
int stonesSum(int l, int r) {
    /* [l, r] */
    return presum[r] - presum[l - 1];
}
/*
dpij:
state:
    set: merge stones from i to j, all methods
    attribute: min cost of the all methods
calc:
    dpij = min(dp[i][k] +  dp[k+1][j]) + sum(stones[i~j]),
        for all k in [i...j-1]
init dp:
    dp[i][i] = 0 for all i in [1...N]
    else dp[i][j] = INF;
*/
int solve() {
    /* init */
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= N; i++) {
        cin >> stones[i];
        presum[i] = presum[i - 1] + stones[i];
        dp[i][i] = 0; /* not moved 0 */
    }

    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len - 1 <= N; i++) {
            int j = i + len - 1;
            if (debug)
                cout << "i,j: " << i << ", " << j << " len: " << len << endl;
            for (int k = i; k <= j - 1; k++) {
                if (debug)
                    cout << " k: " << k << " dp[i][k] + dp[k + 1][j]: "
                         << dp[i][k] + dp[k + 1][j] << endl;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] += stonesSum(i, j);
            if (debug)
                cout << " dp[i][j]: " << dp[i][j] << endl;
        }
    }
    return dp[1][N];
}

int main() {
    cin >> N;
    int res = solve();
    // print();
    // cout << stonesSum(1, 2) << endl;
    // cout << stones[1] + stones[2] << endl;
    cout << res << endl;
}