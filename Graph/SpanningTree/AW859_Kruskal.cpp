/*
https://www.acwing.com/problem/content/861/

n <= 1e5
m <= 2e5
abs(w) <= 1e3
稀疏图
使用 Prime O(N^2) TLE
使用 Kruskal O(m logm)

Kruskal
1. 将所有边按权重从小到大排序 O(m logm)
2. 枚举每条边 ab, 权重 w: O(m), 并查集
    if ab 不连通, 将 ab加入集合

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

const int N = 1e5 + 10, M = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m;

int p[N]; /* for 并查集 */

int find(int x) {
    if(p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}
struct Edge {
    int u, v, w;
    bool operator<(const Edge& rhs) const { return w < rhs.w; };
} edges[M];

int kruskal() {
    sort(edges, edges + m);
    for(int i = 1; i <= n; i++)
        p[i] = i;
    int res = 0; /* weight sum of SMT */
    int cnt = 0; /* edges in the tree */
    for(int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        int pu = find(u), pv = find(v);
        if(pu != pv) {
            /* not in same set */
            p[pu] = pv; /* merge */
            res += w;
            cnt++;
        }
    }
    if(cnt < n - 1) {
        return INF;
    } else {
        return res;
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = { a, b, c };
    }
    auto res = kruskal();
    if(res == INF) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }
}