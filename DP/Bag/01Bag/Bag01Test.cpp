#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N, V, v, w;

int dp[MAXN][MAXN];

void print_dp() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= V; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> N >> V;
    // for (int i = 1; i <= N; i++) {
    //     cin >> v >> w;
    //     for (int j = v; j <= V; j++)
    //         dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v] + w); xxx
    // }
    for (int i = 1; i <= N; i++) {
        cin >> v >> w;
        for (int j = 1; j <= V; j++) {
            if (j < v)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v] + w);
            // dp[i][j] = j < v ? dp[i - 1][j] : max(dp[i-1][j], dp[i - 1][j -
            // v] + w);
        }
    }
    print_dp();
    cout << dp[N][V];
}
/*
4 5
1 2
2 4
3 4
4 5
*/