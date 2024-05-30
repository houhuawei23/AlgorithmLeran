/*
每组物品有若干个，同一组内的物品最多只能选一个。
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXV = 105;
const int MAXS = 105;

int N, V;
int s[MAXN];

int v[MAXS];
int w[MAXS];

int dp[MAXN][MAXV];

void print_dp() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void solveBase() {
    for (int i = 1; i <= N; i++) {
        cin >> s[i];
        for (int k = 1; k <= s[i]; k++) {
            cin >> v[k] >> w[k];
        }
        for (int j = 1; j <= V; j++) {
            int groupMax = INT32_MIN;
            for (int k = 1; k <= s[i]; k++) {
                if (j >= v[k])
                    groupMax = max(groupMax, dp[i - 1][j - v[k]] + w[k]);
            }
            dp[i][j] = max(dp[i - 1][j], groupMax);
        }
    }
}

int main() {
    cin >> N >> V;
    solveBase();
    // print_dp();
    cout << dp[N][V];
}

/*

输入样例
3 5
2
1 2
2 4
1
3 4
1
4 5
输出样例：
8
*/