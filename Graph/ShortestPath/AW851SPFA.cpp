/*
https://www.acwing.com/problem/content/853/

n, m <= 1e5
w <= 1e4
Bellman Ford 做了很多无用功, 每次迭代都要更新所有边
    O(nm) = 1e10 TLE

SPFA:
若某结点dist被更新了, 则检查该结点的所有相邻结点, 并将成功更新的邻结点加入队列
    worst: O(nm)

输入样例：
3 3
1 2 5
2 3 -3
1 3 4
输出样例：
2

1e5 * 
什么样的图能卡spfa
https://www.acwing.com/file_system/file/content/whole/index/content/7961829/
https://blog.csdn.net/muxidreamtohit/article/details/7894298
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const uint8_t INFBYTE = 0x3f;
const int INFINT = 0x3f3f3f3f;

int firstEdge[N], endPoint[N], nextEdge[N], weight[N], idx;

int dist[N];

bool inQueue[N]; /* wheter the point is in the queue */
int n, m;

void add(int u, int v, int w) {
    weight[idx] = w;
    endPoint[idx] = v;
    nextEdge[idx] = firstEdge[u];
    firstEdge[u] = idx;
    idx++;
}
pair<bool, int> spfa() {
    memset(dist, INFBYTE, sizeof(dist));
    queue<int> q;
    dist[1] = 0;
    q.push(1); /* start point */
    while(not q.empty()) {
        auto cur = q.front();
        q.pop();
        inQueue[cur] = false;
        for(int edge = firstEdge[cur]; edge != -1; edge = nextEdge[edge]) {
            auto end = endPoint[edge];
            if(dist[end] > dist[cur] + weight[edge]) {
                dist[end] = dist[cur] + weight[edge];
                if(not inQueue[end]) {
                    q.push(end);
                    inQueue[end] = true;
                }
            }
        }
    }
    if(dist[n] ==  INFINT) {
        /* 不是遍历所有边更新所有的 endpoint, 
        ** 队列保证了只会更新起点所能到达的点 */
        return { false, -1 };
    } else {
        return { true, dist[n] };
    }
}
int main() {
    cin >> n >> m;
    memset(firstEdge, -1, sizeof(firstEdge));
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    auto res = spfa();
    if(res.first) {
        cout << res.second << endl;
    } else {
        cout << "impossible" << endl;
    }
}