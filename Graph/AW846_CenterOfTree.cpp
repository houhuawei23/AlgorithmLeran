/*
Center of Tree.
https://www.acwing.com/problem/content/848/
Graph BFS;

输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
输出样例：
4
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = N * 2;

int h[N], e[M], ne[M], idx;

bool st[N];  // already go

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int n;
int ans = N;

/*
void dfs(int u) {
    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j])
            dfs(j);
    }
}
*/

int dfs(int u) {
    st[u] = true;

    int size = 0, sum = 0;

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (st[j])
            continue;
        int s = dfs(j);  // size of child
        size = max(size, s);
        sum += s;
    }
    size = max(size, n - sum - 1);
    ans = min(ans, size);
    return sum + 1;
}

int main() {
    int idx = 0;
    memset(h, -1, sizeof(h));
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}