/* AcWing
1250. 格子游戏
https://www.acwing.com/problem/content/1252/
n <= 200
m <= 24000
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 210, M = 24010;
int n, m;
int p[N * N + N];

void init_set() {
    for(int i = 1; i <= n * n + n; i++) p[i] = i;
}
int find_set(const int x) {
    return p[x] = (p[x] == x ? p[x] : find_set(p[x]));
    // if(p[x] != x) { p[x] = find_set(p[x]); }
    // return p[x];
}

void merge_set(int x, int y) {
    int px = find_set(x), py = find_set(y);
    p[px] = py;
}
int main() {
    cin >> n >> m;
    init_set();
    for(int i = 1; i <= m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        int idx1 = x * n + y;
        int idx2 = -1;
        if(c == 'D') {
            idx2 = (x + 1) * n + y;
        } else if(c == 'R') {
            idx2 = x * n + y + 1;
        }
        assert(idx2 != -1);
        int p1 = find_set(idx1), p2 = find_set(idx2);
        if(p1 == p2) {
            /* same set, closed */
            cout << i << endl;
            return 0;
        } else {
            merge_set(idx1, idx2);
        }
    }
    cout << "draw" << endl;
}
/*
输入样例：
3 5
1 1 D
1 1 R
1 2 D
2 1 R
2 2 D
输出样例：
4
*/