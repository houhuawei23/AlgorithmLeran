#include <bits/stdc++.h>
using namespace std;

bool debug = false;
const int MAXN = 35;
const int MAXSum = 3e5 + 10;

int n, x;
int Sum = 0;

int a[MAXN];

int dp[MAXN][MAXSum];
/*
dp[i][j]:
从前 i 个物品中选, 总价格 <= j, 最大总价格
对于 物品 i:
N: dp[i-1][j]
Y: dp[i-1][j-ai] + ai
result:
Sum - dp[n][Sum-x]
*/

void dp01() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= Sum - x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
            }
        }
    }
}
int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Sum += a[i];
    }
    // dp01();
    int V = Sum - x;
    auto dpfunc = [&]() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= V; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= a[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
                }
            }
        }
    };
    dpfunc();
    cout << Sum - dp[n][Sum - x];
}

/*
4 100
20
90
60
60

*/