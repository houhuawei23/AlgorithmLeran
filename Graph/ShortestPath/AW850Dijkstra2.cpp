/*
n points, m edges
repeat edges, circul, weight >= 0
find shortest distance between 1 and n, else -1

n, m <= 1.5e5
normal Dijkstra: O(N^2), TLE
Heap Optimization: O(m logm), for 稀疏图, 邻接表存

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
typedef pair<int, int> PII;
const int N = 1.5e5 + 10;
const uint8_t INFBYTE = 0x3f;
const int INFINT = 0x3f3f3f3f;

int firstEdge[N], endPoint[N], nextEdge[N], weight[N], idx;
int dist[N];
bool st[N]; /* true is determined */

int n, m;
void add(int a, int b, int c) {
    weight[idx] = c;
    endPoint[idx] = b;
    nextEdge[idx] = firstEdge[a];
    firstEdge[a] = idx;
    idx++;
}

int dijkstra() {
    memset(dist, INFBYTE, sizeof(dist));
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    // 这里heap中为什么要存pair呢，首先小根堆是根据距离来排的，所以有一个变量要是距离，
    // 其次在从堆中拿出来的时候要知道知道这个点是哪个点，不然怎么更新邻接点呢？所以第二个变量要存点。
    heap.push({ 0, 1 }); /* first: distance, second: point id*/
    while(heap.size()) {
        PII p = heap.top();
        heap.pop();
        int distance = p.first, cur = p.second;
        if(st[cur]) continue;
        /* mark as determined */
        st[cur] = true;
        for(auto edge = firstEdge[cur]; edge != -1; edge = nextEdge[edge]) {
            int end = endPoint[edge];
            if(dist[end] > distance + weight[edge]) {
                dist[end] = distance + weight[edge];
                heap.push({ dist[end], end });
            }
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
    memset(firstEdge, -1, sizeof(firstEdge));
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout << dijkstra() << endl;
}