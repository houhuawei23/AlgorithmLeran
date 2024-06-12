/*
一个图是二分图 当且仅当 图中不含奇数环

输入样例：
4 4
1 3
1 4
2 3
2 4
输出样例：
Yes
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;

int n, m;
int firstEdge[N], endPoint[M], nextEdge[M], idx;

int color[N];

void add(int u, int v) {
    endPoint[idx] = v;
    nextEdge[idx] = firstEdge[u];
    firstEdge[u] = idx;
    idx++;
}
/* c: 1 or 2 */
bool dfs(int u, int c) {
    color[u] = c;
    for(int edge = firstEdge[u]; edge != -1; edge = nextEdge[edge]) {
        int end = endPoint[edge];
        /* not colored */
        if(color[end] == 0) {
            if(not dfs(end, 3 - c)) {
                return false;
            }
        } else if(color[end] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    memset(firstEdge, -1, sizeof(firstEdge));
    while(m--) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            if(not dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
