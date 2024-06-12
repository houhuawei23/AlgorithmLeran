/*
https://www.acwing.com/problem/content/860/

求最小生成树:
给定一个无向图，在图中选择若干条边把图的所有节点连起来, 要求边长之和最小。

Prime: 贪心策略 逐步扩展生成树,每次选择边权最小的点加入生成树

n <= 500
m <= 1e5
稠密图
O(N^2): N iters, each iter traverse all N points

if want to record the MST, can use pre[N], record the edge

int dist[n], state[n], pre[n];
dist[1] = 0;
for(i : 1 ~ n) {
    t <- 没有连通起来，但是距离连通部分最近的点;
    state[t] = 1;
    更新 dist 和 pre;
}

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N]; /* dist[i]: distance between i and spining tree set */
bool st[N];  /* true if i in set */

int prime() {
    memset(dist, 0x3f, sizeof(dist));
    int res = 0;
    /* n times iter, each iter add one point to the set */
    for(int i = 0; i < n; i++) {
        /* find closest point out of the set */
        int t = -1;
        for(int j = 1; j <= n; j++) {
            if(not st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        if(i != 0 and dist[t] == INF) {
            /* if i == 0, out, add i to set
            ** if i != 0, and dist[t] == INf,
            ** means that the graph is not conncted, return INF */
            return INF;
        }
        /* 先 add to res, 再更新; 否则更新后 dist[t] = 0 */
        if(i != 0)
            res += dist[t];
        /* using t to update points out of the set */
        for(int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], g[t][j]);
        }
        /* add t to set */
        st[t] = true;
    }
    return res;
}

int primeBetter() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    int res = 0;
    /* n times iter, each iter add one point to the set */
    for(int i = 0; i < n; i++) {
        int t = -1;
        for(int j = 1; j <= n; j++) {
            if(not st[j] && (t == -1 or dist[t] > dist[j]))
                t = j;
        }
        if(dist[t] == INF) {
            return INF;
        }
        res += dist[t];
        st[t] = true;
        for(int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], g[t][j]);
            /*
            if(dist[j] > g[t][j]) {
                dist[j] = g[t][j];
                pre[j] = t;
            }
            */
        }
    }
    return res;
}
int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    auto res = prime();
    if(res == INF) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
