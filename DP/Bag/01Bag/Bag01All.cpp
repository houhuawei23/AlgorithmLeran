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
/*
恰好装满V时所能的到的价值最大值
*/

int main() {
    cin >> N >> V;

    // init dp
    for(int j =1; j<=V; j++) {
        dp[0][j] = INT32_MIN;
    }


    for (int i = 1; i <= N; i++) {
        cin >> v >> w;
        for (int j = 1; j <= V; j++) {
            dp[i][j] = j < v ? dp[i - 1][j] : max(dp[i-1][j], dp[i - 1][j - v] + w);
        }
    }
    print_dp();
    cout << dp[N][V];
}