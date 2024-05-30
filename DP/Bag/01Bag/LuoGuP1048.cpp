#include <bits/stdc++.h>

using namespace std;

const int MAXT = 1005;
const int MAXM = 105;

int T, M;

int dp[MAXM][MAXT];

int main() {
    cin >> T >> M;
    for (int i = 1; i <= M; i++) {
        int t, w;
        cin >> t >> w;
        for (int j = 1; j <= T; j++) {
            dp[i][j] =
                j < t ? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - t] + w);
        }
    }
    cout << dp[M][T];
}