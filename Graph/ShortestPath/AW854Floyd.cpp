/*
https://www.acwing.com/problem/content/856/
多源汇最短路, 重边-自环-负权
n m k
x y z * m
x y * k

n <= 200
k <= n^2 <= 4e4
m <= 2e4
abs(w) <= 1e4
if SPFA: n*m*k = 200 * 2e4 * 4e4 = 1.6e11 (TLE)
use Floyd: DP
    d[i][j] = min(d[i][j], d[i][k] + d[k][j])

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 210;
const int INF = 0x3f3f3f3f;
int d[N][N];
int n, m, k;

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        /* keep min edge */
        d[x][y] = min(d[x][y], z);
    }
    floyd();
    while(k--) {
        int x, y;
        cin >> x >> y;
        if(d[x][y] > INF / 2) {
            cout << "impossible" << endl;
        } else {
            cout << d[x][y] << endl;
        }
    }
}

/*
输入样例：
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
输出样例：
impossible
1

*/