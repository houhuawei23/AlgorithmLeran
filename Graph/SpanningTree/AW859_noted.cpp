/*Kruskal算法求最小生成树-并查集的应用*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;  // n个点m条边
int p[N];  // 并查集

struct Edge {
    int a, b, w;
    // 重载<,用于sort升序排序
    bool operator<(const Edge& W) const { return w < W.w; }
} edges[M];  // 存储边的图

// 并查集-找到x的祖宗结点
int find(int x) {
    if(p[x] != x)
        p[x] = find(p[x]);  // 查找祖宗结点+路径压缩
    return p[x];
}

int kruskal() {
    // 将所有边按权重大小升序排序
    sort(edges, edges + m);

    // 初始化并查集
    for(int i = 1; i <= n; i++)
        p[i] = i;  // 每个点的祖宗都是自己

    // 升序枚举每条边
    int res = 0, cnt = 0;
    for(int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        // 判断a,b是否联通<==>比较a,b的祖宗结点是否相同
        a = find(a), b = find(b);
        if(a != b) {
            p[a] = b;
            res += w;  // res记录权重和
            cnt++;     // cnt记录最小生成树中的边数
        }
    }

    // 若cnt中边数不等于n-1,则说明不存在最小生成树
    if(cnt < n - 1)
        return INF;
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = { a, b, w };
    }

    int t = kruskal();

    if(t == INF)
        puts("impossible");
    else
        printf("%d\n", t);

    return 0;
}
