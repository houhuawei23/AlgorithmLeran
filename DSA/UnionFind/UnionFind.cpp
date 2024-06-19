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
/*
template< class ForwardIt, class T >
void iota( ForwardIt first, ForwardIt last, T value );

Fills the range [first, last) with sequentially increasing values,
starting with value and repetitively evaluating ++value.
*/
struct dsu {
    vector<size_t> pa;

    explicit dsu(size_t size) : pa(size) { iota(pa.begin(), pa.end(), 0); }
};
size_t dsu::find(size_t x) { return pa[x] == x ? x : find(pa[x]); }
size_t dsu::findBetter(size_t x) {
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}
void dsu::unite(size_t x, size_t y) { pa[find(x)] = find(y); }

struct dsu {
    vector<size_t> pa, size;

    explicit dsu(size_t size_) : pa(size_), size(size_, 1) {
        iota(pa.begin(), pa.end(), 0);
    }

    void unite(size_t x, size_t y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(size[x] < size[y]) swap(x, y);
        pa[y] = x;
        size[x] += size[y];
    }
};
/*
要删除一个叶子节点，我们可以将其父亲设为自己。
为了保证要删除的元素都是叶子，我们可以预先为每个节点制作副本，并将其副本作为父亲。
*/
struct dsu {
    vector<size_t> pa, size;

    explicit dsu(size_t size_) : pa(size_ * 2), size(size_ * 2, 1) {
        iota(pa.begin(), pa.begin() + size_, size_);
        iota(pa.begin() + size_, pa.end(), size_);
    }

    void erase(size_t x) {
        --size[find(x)];
        pa[x] = x;
    }
};
/*
与删除类似，通过以副本作为父亲，保证要移动的元素都是叶子。
*/
void dsu::move(size_t x, size_t y) {
    auto fx = find(x), fy = find(y);
    if(fx == fy) return;
    pa[x] = fy;
    --size[fx], ++size[fy];
}
