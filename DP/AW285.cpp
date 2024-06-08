/*
285. 没有上司的舞会
N 1 ~ N
Hi
max Sum Hi

N
Hi x N
L, K x N-1
K is the father of L
输入样例：
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
输出样例：
5
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6010;

int n;
int h[MAXN], e[MAXN], ne[MAXN], idx;
int happy[MAXN];
int f[MAXN][2];
bool has_father[MAXN];
/*
对于第i个职员, 加入or不加入
if 加入: delete children of i from state
    how to delete? how can you extract child information
    from f[i]? only a number.
    need to record the path?
if not add: pass
f[i][j]
考虑第i个职员, 所有可能的职员组合情况(合法)
属性: sum happy 最大值
f[i][0]: no choose i
    for all child j of i:
        f[i][0] += max(f[j][0], f[j][1])
f[i][1]: choose i: cant choose its child.
    for all child j of i:
        f[i][1] += f[j][0]
*/
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int u) {
    f[u][1] = happy[u];
    for(int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> happy[i];
    }
    memset(h, -1, sizeof(h));
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(b, a); /* b -> a, father -> child */
        has_father[a] = true;
    }
    int root = 1;
    while(has_father[root]) {
        root++;
    }
    // cout << "root: " << root << endl;
    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}