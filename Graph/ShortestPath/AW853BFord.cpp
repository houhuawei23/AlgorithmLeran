/*
https://www.acwing.com/problem/content/855/

负权图最短路, 限制 k

n, k <= 500
m <= 1e4
|w| <= 1e4

输入样例：
3 3 1
1 2 1
2 3 1
1 3 3
输出样例：
3

Dijkstra 适用于w >=0的图, 当存在负边时, 在某次迭代中确定的 closest point (c),
不能够直接确定为全局最短路径, 因为之后的迭代可能存在负边, 反而使 1 -> c
路径长度更短. 也就是说, 某次迭代找到的局部最优, 不能够作为全局最优,
以后也不能以此为基础进行迭代.

Bellman Ford 适用于存在负边 或限制经过边数为k的情况, 思想时每次迭代更新所有的边,
类似于不动点算法, 迭代 n 次 (点数) 后, 若还会发生更新操作, 说明存在负回路.
若某次迭代后不再更新, 说明已经达到不动点, 找到了全局稳定解, 即最短路径解.

迭代完第 k 次时的 dist:
    从 1 出发到 other points, 经过 <= k 条边时的最短路径长度.

若存在 1 -> n的最短路径, 则只需要迭代 n - 1 次即可, 因为最短路一定 <= n - 1

Bellman Ford
for k iter:
    update all edges:
    for each edge {u, v, w}:
        dist[v] = min(dist[v], dist[u] + w);

O(nm) = 500 * 1e4 = 5*1e6
n points, m edges
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int M = 1e4 + 5;
const uint8_t INFBYTE = 0x3f;
const int INFINT = 0x3f3f3f3f; /* 1e9 */

struct Edge {
    int u, v, w;
} edges[M];

int n, m, k;
int dist[N];
int last[N];

pair<bool, int> bellmanFold() {
    memset(dist, INFBYTE, sizeof(dist));
    dist[1] = 0;
    for(int i = 0; i < k; i++) {
        /* last <- dist, avoid series update,
        ** only use the former iteration result (last) */
        memcpy(last, dist, sizeof(dist));
        for(int j = 0; j < m; j++) {
            const auto e = edges[j];
            dist[e.v] = min(dist[e.v], last[e.u] + e.w);
        }
    }
    if(dist[n] > INFINT / 2) {
        /* may exist neg edge, so dist[n] may < INFINT,
        ** but w * k <= 1e4 * 500 = 5e6, INFINT ~= 1e9 */
        return { false, -1 };
    } else {
        return { true, dist[n] };
    }
}
int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = { u, v, w };
    }
    auto res = bellmanFold();
    if(res.first) {
        cout << res.second << endl;
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}
/*
串联：
由于这个算法的特性决定，每次更新得到的必然是在多考虑1条边之后能得到的全局的最短路。
而串联指的是一次更新之后考虑了不止一条边：由于使用了松弛，某节点的当前最短路依赖于其所有入度的节点的最短路；
假如在代码中使用dist[e.b]=min(dist[e.b],dist[e.a] + e.c);
我们无法保证dist[e.a]是否也在本次循环中被更新，
如果被更新了，并且 dist[e.b] > dist[e.a] + e.c，
那么会造成当前节点在事实上“即考虑了一条从某个节点指向a的边，也考虑了a->b”，共两条边。
而使用dist[e.b] = min(dist[e.b],last[e.a] + e.c);
可以保证a在dist更新后不影响对b的判定，因为后者使用last数组，保存着上一次循环中的dist的值。

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/48523/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/