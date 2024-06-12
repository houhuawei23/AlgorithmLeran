/*
Topo Sort
https://www.acwing.com/problem/content/850/
输入样例：
3 3
1 2
2 3
1 3
输出样例：
1 2 3
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;

int h[N], e[M], ne[M], idx;

int in[N];  // in degrees

// bool st[N];  // already go

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int n, m;
vector<int> res;

bool topSort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0)
            q.push(i);
    }
    while(q.size()) {
        auto cur = q.front();
        q.pop();
        res.push_back(cur);
        for(int edge = h[cur]; edge != -1; edge = ne[edge]) {
            auto end = e[edge];
            in[end]--;
            if(in[end] == 0)
                q.push(end);
        }
    }
    return res.size() == n;
}

int main() {
    int idx = 0;
    memset(h, -1, sizeof(h));

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        in[b]++;
    }
    if(topSort()) {
        for(auto node : res) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}