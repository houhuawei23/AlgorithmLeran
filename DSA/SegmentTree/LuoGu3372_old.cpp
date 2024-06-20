/*
2022-11-06 00:34
*/
// 线段树-区间和

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;

int a[MAXN] = {};
ll t[MAXN << 2] = {};
ll lazy[MAXN << 2] = {};

void pushup(int k) { t[k] = t[k << 1] + t[k << 1 | 1]; }
void f(int k, int l, int r, int lz) {
    lazy[k] += lz;
    t[k] += lz * (r - l + 1);
}
void pushdown(int k, int l, int r) {
    if(lazy[k]) {
        int tp = lazy[k];
        int m = l + ((r - l) >> 1);
        f(k << 1, l, m, tp);
        f(k << 1 | 1, m + 1, r, tp);
        //		lazy[k << 1] += tp;
        //		lazy[k << 1 | 1] += tp;
        //
        //		t[k << 1] += tp*(r-l+1);
        //		t[k << 1 | 1] += tp*(r-l+1);
        lazy[k] = 0;
    }
}
void build(int k, int l, int r) {
    if(l == r)
        t[k] = a[l];
    else {
        int mid = l + ((r - l) >> 1);
        build(k << 1, l, mid);
        build(k << 1 | 1, mid + 1, r);
        pushup(k);
    }
}
ll query(int ql, int qr, int l, int r, int k) {
    if(ql <= l && r <= qr)
        return t[k];
    else {
        pushdown(k, l, r);
        int mid = l + ((r - l) >> 1);
        ll sum = 0;
        if(ql <= mid) sum += query(ql, qr, l, mid, k << 1);
        if(mid + 1 <= qr) sum += query(ql, qr, mid + 1, r, k << 1 | 1);
        return sum;
    }
}

void updata1(int p, int v, int l, int r, int k) {
    if(l == r)
        a[p] += v, t[k] += v;
    else {
        int m = l + ((r - l) >> 1);
        if(p <= m)
            updata1(p, v, l, m, k << 1);
        else
            updata1(p, v, m + 1, r, k << 1 | 1);
        pushup(k);
    }
}

void updata2(int L, int R, int v, int l, int r, int k) {
    if(L <= l && r <= R)
        lazy[k] += v, t[k] += v * (r - l + 1);
    else {
        pushdown(k, l, r);
        int m = l + ((r - l) >> 1);
        if(L <= m) updata2(L, R, v, l, m, k << 1);
        if(R > m) updata2(L, R, v, m + 1, r, k << 1 | 1);
        pushup(k);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int op, x, y, k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    //	for(int i=1; i<=4*n; i++){
    //		cout<<t[i]<<" ";
    //	}
    while(m--) {
        // cout<<"$"<<endl;
        cin >> op;
        // cout<<op<<endl;
        if(op == 1) {
            cin >> x >> y >> k;
            updata2(x, y, k, 1, n, 1);
        }
        if(op == 2) {
            cin >> x >> y;
            cout << query(x, y, 1, n, 1) << endl;
            ;
        }
    }
    return 0;
}