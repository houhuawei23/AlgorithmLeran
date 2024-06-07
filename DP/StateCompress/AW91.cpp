/*
f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j])

O(2^22 * 22 * 22) = 2e8
https://www.acwing.com/problem/content/93/
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20, MAXM = 1 << MAXN;

int f[MAXM][MAXN], w[MAXN][MAXN];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    /* init +inf */
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    int m = 1 << n;
    /* all posible path num/path, 1 means this node is visited */
    /* 0 -> n-1
     * f[i][j]: 0->X->X->...->j, (i >> j & 1 == true, passed j)
     * f[i][k]: j not in path i
     * 0->...->k->j: f[i][k] + w[k, j]
     */
    /* for all posible path */
    for(int i = 0; i < m; i++) {
        /* for each path end */
        for(int j = 0; j < n; j++) {
            /* i has passed the node j */
            if(i >> j & 1)
                for(int k = 0; k < n; k++) {
                    /* i has passed the node k*/
                    if(i >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                }
        }
    }
    /* f[1<<n - 1][n-1], passed all nodes, end with n - 1*/
    cout << f[(1 << n) - 1][n - 1] << endl;
}

/*
输入样例：
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0
输出样例：
18
*/