/*
Integer Division. 整数划分.
https://www.acwing.com/problem/content/902/

计数类DP

输入样例:
5
输出样例：
7
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int MOD = 1e9 + 7;

int n;

int f[MAXN][MAXN];
/*
转换成恰好装满的完全背包问题:
V = n
物品: 1 ~ n, n 个正整数, 每种物品能取无线多次
朴素完全背包: O(N*N*N)
顺序优化: O(N*N)
f[i][j] 恰好装满的方法数
题意没理解好...出发点错, 很难查错
*/
void print_f() {
    cout << "f: " << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}
int solve(const int n) {
    /* init dp */
    const int V = n;
    for (int i = 0; i <= n; i++) {
        f[i][0] = 1;
        f[i][1] = 1;
        f[1][i] = 1;
    }
    // print_f();
    for (int i = 2; i <= n; i++) {
        const int v = i;
        for (int j = 2; j <= V; j++) {
            /* 取 k 个 i */
            for (int k = 0; k * v <= j; k++) {
                f[i][j] += f[i - 1][j - k * i];
                f[i][j] %= MOD;
            }
        }
    }
    // print_f();
    return f[n][V];
}

int solveOpt(const int n) {
    /* init dp */
    const int V = n;
    for (int i = 0; i <= n; i++) {
        f[i][0] = 1;
    }
    // print_f();
    for (int i = 1; i <= n; i++) {
        const int v = i;
        for (int j = 1; j <= V; j++) {
            /* 取 k 个 i */
            for (int k = 0; k * v <= j; k++) {
                f[i][j] += f[i - 1][j - k * i];
                f[i][j] %= MOD;
            }
        }
    }
    // print_f();
    return f[n][V];
}
int solveOptMore(const int n) {
    const int V = n;
    for (int i = 0; i <= n; i++) {
        f[i][0] = 1;
    }
    // print_f();
    for (int i = 1; i <= n; i++) {
        const int v = i;
        for (int j = 1; j <= V; j++) {
            /* 取 k 个 i */
            if (j >= i) {
                f[i][j] = (f[i - 1][j] + f[i][j - i]) % MOD;
            } else {
                f[i][j] = f[i - 1][j] % MOD;
            }
        }
    }
    // print_f();
    return f[n][V];
}

int dp[MAXN];
int solveOptBest(const int n) {
    const int V = n;
    dp[0] = 1;
    // print_f();
    for (int i = 1; i <= n; i++) {
        const int v = i;
        for (int j = i; j <= V; j++) {
            /* 取 k 个 i */
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    // print_f();
    return dp[n];
}

int main() {
    cin >> n;
    int res = solveOptBest(n);
    cout << res << endl;
}
