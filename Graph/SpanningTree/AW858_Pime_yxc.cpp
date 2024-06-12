/*

与dijkstra不同，prim需要迭代n次
最小生成树是针对无向图的，所以在读入边的时候，需要赋值两次
要先累加再更新，避免t有自环，影响答案的正确性。后更新不会影响后面的结果么？不会的，因为dist[i]为i到集合S的距离，当t放入集合后，其dist[t]就已经没有意义了，再更新也不会影响答案的正确性。
需要特判一下第一次迭代，在我们没有做特殊处理时，第一次迭代中所有点到集合S的距离必然为无穷大，而且不会进行更新(也没有必要)，所以不需要将这条边(第一次迭代时，找到的距离集合S最短的边)累加到答案中，也不能认定为图不连通。
如果需要设置起点为i的话，在初始化dist数组之后，dist[i] =
0即可，这样也可以省去每轮迭代中的两个if判断。

https://www.acwing.com/solution/content/38312/



作者：yxc
链接：https://www.acwing.com/activity/content/code/content/48767/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF)
            return INF;

        if (i)
            res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF)
        puts("impossible");
    else
        printf("%d\n", t);

    return 0;
}
