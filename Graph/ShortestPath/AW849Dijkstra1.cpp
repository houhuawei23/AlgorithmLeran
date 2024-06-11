/*
Dijkstra
https://www.acwing.com/problem/content/description/851/
1. find next point (p) closest to source.
2. the shortest path length from source to p is determined.
3. update all other points, as p is determined: min(dist[k], dist[p] + g[p][k])

n <= 500
m <= 10^5
朴素版: for 稠密图
O(n^2) = 2.5e5

输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const int INFBYTE = 0x3f;
const int INFINT = 0x3f3f3f3f;
int n, m;
int g[N][N]; /* g[i][j]: distance between i and j */
int dist[N]; /* dist[i]: 1 to i shortest path distance */
bool st[N];  /* true if dist[i] is determined */

int dijistra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 0; i < n - 1; i++) { /* n */
        int t = -1;
        for(int j = 1; j <= n; j++) {
            /* find closeset point that not determined */
            if(!st[j] and (t == -1 or dist[t] > dist[j])) {
                t = j;
            }
        }
        st[t] = true;
        /* 1 -> t determined, find next point j,
        ** min 1->t->j = dist[t] + min(g[t][j]) */
        for(int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if(dist[n] == INFINT) {
        return -1;
    } else {
        return dist[n];
    }
}

int main() {
    cin >> n >> m;
    memset(g, INFBYTE, sizeof(g));
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        /* repeat edge */
        g[x][y] = min(g[x][y], z);
    }
    cout << dijistra() << endl;
    return 0;
}
