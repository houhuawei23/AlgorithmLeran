/*
AcWing 837. 连通块中点的数量
https://www.acwing.com/problem/content/839/
输入样例：
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5
输出样例：
Yes
2
3
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int p[N], cnt[N];

int find(int x) {
    if(p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }
    string op;
    int a, b;
    while(m--) {
        cin >> op;
        if(op == "C") {
            cin >> a >> b;
            int pa = find(a), pb = find(b);
            if(pa != pb) {
                p[pa] = pb;
                cnt[pb] += cnt[pa];
            }
        } else if(op == "Q1") {
            cin >> a >> b;
            int pa = find(a), pb = find(b);
            if(pa == pb) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if(op == "Q2") {
            cin >> a;
            int pa = find(a);
            cout << cnt[pa] << endl;
        }
    }
}