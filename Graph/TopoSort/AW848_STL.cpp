#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N];    // d用来表示一个点的入度
int cnt;     // 求队列中的元素的个数
int top[N];  // 存储队列中的元素
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q.push(i);

    while (q.size()) {
        auto t = q.front();
        top[cnt++] = t;
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j]--;
            if (!d[j])
                q.push(j);
        }
    }
    return cnt == n;
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }

    if (topsort()) {
        for (int i = 0; i < n; i++)
            printf("%d ", top[i]);
        puts("");
    } else {
        puts("-1");
    }
    return 0;
}
