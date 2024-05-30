#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];

void print_dp() {
    cout << "dp: " << endl;
    for (int i = 0; i <= n; i++) {
        // cout << "-inf" << " ";
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] == INT32_MIN) {
                cout << "-i" << " ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }
}

/*
top to down
:= 定义为
dp[i][j] := max[path] Sum(path), s.t. path.final = a[i][j]
then:
dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j]
just: dp[i][j] = max(leftMax, rightMax) + cura

dp init:
dp[i][j] = -INF for i in [0, n], for j in [0, n]
dp[1][1] = a[1][1]
*/
int solveBase() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    /* init dp */
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            dp[i][j] = INT32_MIN;
    }
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }
    int maxSum = INT32_MIN;
    for (int i = 1; i <= n; i++) {
        maxSum = max(maxSum, dp[n][i]);
    }
    return maxSum;
}
/*
down to top:
dp[i][j] := max[reversePath] Sum(reversePath), reversePath.final = a[i][j]
then:
dp[i][j] = max(goLeftMax, goRightMax) + cura
that is:
dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j]

dp init:
dp[n][j] = a[n][j] for j in [1...n]

dp traverse:
for i in [n...1]
    for j in [1...n]

compare to 'top2down', down2top has no careful boundary conditions
*/
int solveYan() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    /* init dp */

    for (int j = 1; j <= n; j++)
        dp[n][j] = a[n][j];

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
        }
    }
    return dp[1][1];
}

int main() {
    cin >> n;
    // int maxSum = solveBase();
    int maxSum = solveYan();
    // print_dp();
    cout << maxSum;
}

/*
输入样例：
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
输出样例：
30

输入
10
-6
-4 -5
-3 7 5
3 7 -2 1
10 2 -6 2 -6
-8 3 8 6 7 9
-4 -10 0 -3 4 9 2
0 5 5 5 10 -6 -5 -4
-9 7 4 9 8 -5 -2 3 2
-7 -4 0 -10 -8 -4 3 -5 8 9

输出
33
标准答案
25
*/