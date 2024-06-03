/*
AcWing847 图中点的层次
n node, m edge, direct edge
len of edge: 1
node idx: 1-n
calc: 1-n min length else -1

输入样例：
4 5
1 2
2 3
3 4
1 3
1 4
输出样例：
1
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;

int h[N], e[M], ne[M], idx;

int d[N];

// bool st[N];  // already go

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int n, m;

int bfs() {
    memset(d, -1, sizeof(d));

    queue<int> q;
    q.push(1);
    d[1] = 0;

    while (not q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}

int main() {
    int idx = 0;
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    // cout<<
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
}