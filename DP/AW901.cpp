/*
901 滑雪
https://www.acwing.com/problem/content/903/

R, C

记忆化搜索, 已经计算过的状态直接返回

输入样例：
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
输出样例：
25
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 310;
int h[N][N];
int f[N][N];
int r, c;
/*

*/
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };

int dp(int i, int j) {
    int& v = f[i][j];
    /* 体现: 记忆化搜索, 已经计算过的状态直接返回
    该问题保证不存在环, 所以递归一定会终止 */
    if(v != -1) {
        return v;
    }
    v = 1;
    for(int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if(x >= 1 && x <= r && y >= 1 && y <= c && h[i][j] > h[x][y]) {
            v = max(v, dp(x, y) + 1);
        }
    }
    return v;
}

void print_f() {
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> h[i][j];
        }
    }

    memset(f, -1, sizeof(f));
    // print_f();
    int res = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            res = max(res, dp(i, j));
        }
    }
    // print_f();
    cout << res << endl;
}