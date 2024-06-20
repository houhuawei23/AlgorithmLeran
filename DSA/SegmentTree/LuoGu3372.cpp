/*
线段树模板题: 区间修改 + 区间和查询
*/
#include <bits/stdc++.h>
using namespace std;
#define ls(p) ((p) << 1)
#define rs(p) (((p) << 1) | 1)
typedef int64_t ll;

const size_t N = 1e5 + 10;

size_t n, m;

int a[N];

ll tree[N * 4];
ll tag[N * 4];

void pushUp(size_t p) { tree[p] = tree[ls(p)] + tree[rs(p)]; }

void build(size_t p, size_t l, size_t r) {
    if(l == r) {
        tree[p] = a[l];
        return;
    }
    size_t mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushUp(p);
}
void addTag(size_t p, size_t l, size_t r, ll d) {
    /* mark p on tag, update tree */
    tag[p] += d;
    tree[p] += d * (r - l + 1);
    /* but children of p, tree[child] are not modified */
}
void pushDown(size_t p, size_t l, size_t r) {
    /* push down tag to child tree */
    if(tag[p]) {
        size_t mid = (l + r) >> 1;
        addTag(ls(p), l, mid, tag[p]);
        addTag(rs(p), mid + 1, r, tag[p]);
        tag[p] = 0;
    }
}

void update(size_t l, size_t r, size_t p, size_t pl, size_t pr, ll d) {
    /* interval update: a [l, r] += d */
    if(l <= pl and pr <= r) {
        addTag(p, pl, pr, d);
        return;
    }
    pushDown(p, pl, pr);
    size_t mid = (pl + pr) >> 1;
    if(l <= mid) { update(l, r, ls(p), pl, mid, d); }
    if(r >= mid + 1) { update(l, r, rs(p), mid + 1, pr, d); }
    pushUp(p);
}

ll query(size_t l, size_t r, size_t p, size_t pl, size_t pr) {
    /* query [l, r], p, [pl, pr] */
    /* [l, r] cover [pl, pr] */
    if(l <= pl and pr <= r) return tree[p];
    /* can not cover */
    pushDown(p, pl, pr);
    ll res = 0;
    size_t mid = (pl + pr) >> 1;
    if(mid >= l) res += query(l, r, ls(p), pl, mid);
    if(mid + 1 <= r) res += query(l, r, rs(p), mid + 1, pr);
    return res;
}

int main() {
    cin >> n >> m;
    for(size_t i = 1; i <= n; i++) { cin >> a[i]; }
    build(1, 1, n);
    while(m--) {
        int q, l, r;
        ll d;
        cin >> q;
        if(q == 1) {
            /* 1 l r d: a[l. r] += d*/
            cin >> l >> r >> d;
            update(l, r, 1, 1, n, d);
        } else if(q == 2) {
            /* 2 l r: query(l ,r) */
            cin >> l >> r;
            cout << query(l, r, 1, 1, n) << endl;
        } else {
            assert(false);
        }
    }
}
/*
11
8
20
*/