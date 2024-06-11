/*

https://www.acwing.com/problem/content/855/

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/48523/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

负权图最短路, 限制 k

输入样例：
3 3 1
1 2 1
2 3 1
1 3 3
输出样例：
3


*/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;

struct Edge {
    int a, b, c;
} edges[M];

int n, m, k;
int dist[N];
int last[N];

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);

    dist[1] = 0;
    for (int i = 0; i < k; i++) {
        memcpy(last, dist, sizeof dist);
        for (int j = 0; j < m; j++) {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    bellman_ford();

    if (dist[n] > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        printf("%d\n", dist[n]);

    return 0;
}
