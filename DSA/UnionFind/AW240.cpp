/*
AcWing
240. 食物链
https://www.acwing.com/problem/content/242/

if x and y are in same set(px == py), we can determine their relation by d.
d[i] record the distance from i to the root of the set tree
    (distance of the food chain, not the set tree height)
- if (d[x] - d[y]) % 3 == 0, same kind
- if ((d[x] - d[y]) % 3 + 3) % 3 == 1, x eat y

if x and y not in the same set (px != py), we need to merge two set tree:
- p[px] = py: set father of px to be py
- determine the 'd' of px
    - if x, y are same kind:
        d[px] = d[y] - d[x]
        because x and y are same kind, so
        - d[x] -> d[y],
        - d[px] -> new d[x] - old d[x] = d[y] - d[x]
    - if x eat y:
        we need to insert x under y, so
        - d[x] -> d[y] + 1
        - d[px] -> new d[x] - old d[x] = d[y] + 1 - d[x]
    we only need to update d of px, because when we update d of px,
    the followings under px will be auto update by the call of find()

because union-find set need to flatten the set tree,
so we need to update the d of each node when calling find()
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
const int K = 1e5 + 10;

int n, k;
int cnt;

int p[N], d[N];

int find(int x) {
    if(p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]]; /* old p[x] */
        p[x] = t;
    }
    return p[x];
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }
    while(k--) {
        int D, x, y;
        cin >> D >> x >> y;
        if(x > n or y > n) {
            cnt++;
            continue;
        }
        int px = find(x), py = find(y);

        if(D == 1) {
            /* say x, y 同类 */
            if(px == py) { /* smae set, can determin relation */
                if((d[x] - d[y]) % 3 != 0) {
                    cnt++;
                    continue;
                }
            } else {
                p[px] = py;          /* merge px to py */
                d[px] = d[y] - d[x]; /* same class */
            }

        } else if(D == 2) {
            /* say x eat y */
            if(x == y) {
                cnt++;
                continue;
            }
            if(px == py) {
                /* in same set, known the relation */
                // if((d[x] - d[y] - 1) % 3)
                if(((d[x] - d[y]) % 3 + 3) % 3 != 1) {
                    cnt++;
                    continue;
                }
            } else {
                /* not int samse set, merge and build relation (d) */
                /* actrualy, we insert x under y,
                ** so the d of px = d[y] + 1 - d[x] */
                p[px] = py; /* merge px to py */
                d[px] = d[y] + 1 - d[x];
            }
        } else {
            assert(false);
        }
    }
    cout << cnt << endl;
}
/*
输入样例：
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
输出样例：
3
*/