// 稠密图 朴素版prim
#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;  // 加上这个可以省去两个if判断

    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (dist[t] == 0x3f3f3f3f)
            return 0x3f3f3f3f;

        res += dist[t];

        st[t] = true;

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == 0x3f3f3f3f)
        puts("impossible");
    else
        cout << t << endl;

    return 0;
}
