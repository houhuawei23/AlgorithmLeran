#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int p[N]; /* for 并查集 */

void init_set() {
    for(int i = 1; i <= N; i++) p[i] = i;
}
int find_set(int x) {
    if(p[x] != x) p[x] = find_set(p[x]);
    return p[x];
    // return p[x] = (p[x] == x ? p[x] : find(p[x]));
}
int find_set_Beta(const int x) {
    /* not recursive implmentation */
    /* 1. find the root*/
    int root = x;
    while(p[root] != root) root = p[root];
    /* 2. set p of nodes on the path to root */
    int cur = x, father;
    while(cur != root) {
        father = p[i];
        p[i] = root;
        cur = father;
    }
    /* return root */
    return root;
}

int d[N];

int findSetWithWeight(int x) {
    if(x != p[x]) {
        /* record father */
        int fa = p[x];
        p[x] = findSetWithWeight(p[x]);
        d[x] += d[t];
    }
    return p[x];
}
void merge_set(int x, int y) {
    x = find_set(x), y = find_set(y);
    if(x != y) p[x] = p[y];  // merge x to y, y is the root
}