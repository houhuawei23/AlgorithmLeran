/*
SPFA判断负环: 按照SPFA更新dist, 如果某个点 p 的 cnt >= n,
说明存在某个到p的最短路径上点数 >= n + 1, 
由抽屉原理可知, 该路径上一定存在负环

输入样例：
3 3
1 2 -1
2 3 4
3 1 -4
输出样例：
Yes
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int M = 1e4 + 10;
const uint8_t INFBYTE = 0x3f;
const int INFINT = 0x3f3f3f3f;
int n, m;

int firstEdge[N], endPoint[M], nextEdge[M], weight[M], idx;

int dist[N], cnt[N];

bool st[N];

void add(int u, int v, int w) {
    weight[idx] = w;
    endPoint[idx] = v;
    nextEdge[idx] = firstEdge[u];
    firstEdge[u] = idx;
    idx++;
}

bool spfaLoopCheck() {
    memset(dist, INFBYTE, sizeof(dist));
    queue<int> q;
    dist[1] = 0;
    /* 放入所有点 */
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    while(not q.empty()) {
        int cur = q.front();
        q.pop();
        st[cur] = false;
        for(int edge = firstEdge[cur]; edge != -1; edge = nextEdge[edge]) {
            int end = endPoint[edge];
            if(dist[end] > dist[cur] + weight[edge]) {
                dist[end] = dist[cur] + weight[edge];
                cnt[end] = cnt[cur] + 1;
                if(cnt[end] >= n) {
                    return true;
                }
                if(not st[end]) {
                    q.push(end);
                    st[end] = true;
                }
            }
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    memset(firstEdge, -1, sizeof(firstEdge));
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    auto res = spfaLoopCheck();
    if(res) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}