#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 510;
int g[N][N], dist[N], path[N];
bool st[N];
int n, m;

void print(int path[]) {
    int i = n;
    vector<int> tmp;
    tmp.push_back(n);
    while(path[i] != -1) {
        tmp.push_back(path[i]);
        i = path[i];
    }
    int len = tmp.size();
    for(int i = len - 1; i >= 0; i--)
        if(i != 0) {
            printf("%d->", tmp[i]);
        } else
            cout << tmp[i];
}

int dijkstra() {
    memset(path, -1, sizeof path);
    memset(dist, 0x3f, sizeof dist);

    dist[1] = 0;  // 节点1到自身的距离为0
    for(int i = 0; i < n; i++) {
        int t = -1;
        for(int j = 1; j <= n; j++)
            /*找到此时dist数组中距源点距离最小的点(也就是dist数组中没被标记过的点中最小值的下标)，
             */
            if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;

        for(int j = 1; j <= n; j++) {
            // 更新dist数组，从此时找到的点t开始扩展，比较从1到j的距离,
            // 与从1到t加上从t到j的距离
            //  dist[j] = min(dist[j], dist[t] + g[t][j]);
            if(dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                path[j] = t;
            }
        }

        st[t] = true;  // 访问过距离最短的点就标记
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    cin >> n >> m;

    memset(g, 0x3f3f3f3f, sizeof g);

    // for(int i = 0; i <= n; i ++)
    // {
    //     for(int j = 0; j <= m; j ++)
    //         cout << g[i][j] << ' ';
    //     cout << endl;
    // }

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    printf("最短路径之和：%d\n", dijkstra());
    cout << "最短路径：";
    print(path);

    return 0;
}
