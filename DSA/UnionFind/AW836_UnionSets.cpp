/*
836. 合并集合
https://www.acwing.com/problem/content/838/

https://blog.csdn.net/raelum/article/details/128766206

n 个数, 1 ~ n
m 个操作:
M a b: merge set(a) and set(b)
Q a b: query set(a) == set(b), Yes/No
n, m <= 1e5
并查集模板
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];

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
    }
    while(m--) {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        if(ch == 'M') {
            p[find(a)] = find(b);
        } else if(ch == 'Q') {
            if(find(a) == find(b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
/*
输入样例：
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
输出样例：
Yes
No
Yes
*/