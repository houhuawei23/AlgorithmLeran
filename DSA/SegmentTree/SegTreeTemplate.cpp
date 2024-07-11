#include <bits/stdc++.h>
using namespace std;

#define ls(x) ((x) << 1)
#define rs(x) (((x) << 1) | 1)
#define mid(l, r) (((l) + (r)) >> 1)

typedef pair<size_t, size_t> Interval;

bool isInterSect(Interval r1, Interval r2) {
    if(r1.first > r2.first) swap(r1, r2);
    /* r1.first <= r2.first */
    if(r1.second >= r2.first) return true;
    return false;
}

template <typename T>
class SegTree {
private:
    vector<T> tree, tag;
    // int n, n4;

    const vector<T>& arrRef;
    const size_t mRoot = 1, mRootStart = 1, mRootEnd;

    void build(const size_t root, const size_t start, const size_t end);
    void pushup(const size_t root);
    void pushdown(const size_t root, const size_t curStart,
                  const size_t curEnd);
    void addtag(const size_t root, const size_t curStart, const size_t curEnd,
                const T val);
    void intervalUpdateImpl(const size_t start, const size_t end, const T val,
                            const size_t root, const size_t curStart,
                            const size_t curEnd);
    T getIntervalSumImpl(const size_t start, const size_t end,
                         const size_t root, const size_t curStart,
                         const size_t curEnd);

public:
    SegTree(const vector<T>& arr)
        : mRootEnd(arr.size()), arrRef(arr), tree(arr.size() << 2, 0),
          tag(arr.size() << 2, 0) {
        /* idx start from 1*/
        assert(arr.size() >= 1 and arr.at(0) == 0);
        build(mRoot, mRootStart, mRootEnd);
    }

    void intervalUpdate(const size_t start, const size_t end, const T val);

    T getIntervalSum(const size_t start, const size_t end);
};
template <typename T>
void SegTree<T>::build(const size_t root, const size_t start,
                       const size_t end) {
    /* leaf node */
    if(start == end) {
        tree[root] = arrRef[start];
        return;
    }
    /* divide */
    const size_t Mid = mid(start, end);

    build(ls(root), start, Mid);
    build(rs(root), Mid + 1, end);
    /* calc root */
    pushup(root);
}
template <typename T>
void SegTree<T>::pushup(const size_t root) {
    /* gather children value, push up to root */
    /* interval sum */
    tree[root] = tree[ls(root)] + tree[rs(root)];
    /* max/min */
    // tree[root] = min(tree[ls(root)], tree[rs(root)]);
}
template <typename T>
void SegTree<T>::pushdown(const size_t root, const size_t curStart,
                          const size_t curEnd) {
    /* push root tag to children,
    because we need to update child interval of root,
    so the tag of root will be invalid,
    but its children must record root's tag */
    if(tag[root]) {
        const size_t curMid = mid(curStart, curEnd);
        addtag(ls(root), curStart, curMid, tag[root]);
        addtag(rs(root), curMid + 1, curEnd, tag[root]);
        tag[root] = 0;
    }
}

template <typename T>
void SegTree<T>::addtag(const size_t root, const size_t curStart,
                        const size_t curEnd, const T val) {
    assert(curStart <= curEnd);
    tag[root] += val;
    tree[root] += val * (curEnd - curStart + 1);
}
template <typename T>
void SegTree<T>::intervalUpdate(const size_t start, const size_t end,
                                const T val) {
    intervalUpdateImpl(start, end, val, mRoot, mRootStart, mRootEnd);
}
template <typename T>
void SegTree<T>::intervalUpdateImpl(const size_t start, const size_t end,
                                    const T val, const size_t root,
                                    const size_t curStart,
                                    const size_t curEnd) {
    assert(curStart <= curEnd);
    /* assert Intersect */
    assert(isInterSect({ start, end }, { curStart, curEnd }));
    /* query interval complete cover cur node interval
    ** start <= curStart ~ curEnd <= end */
    if(start <= curStart and curEnd <= end) {
        addtag(root, curStart, curEnd, val);
        return;
    }
    /* else: cur Interval of root is not in [start, end],
    ** need divide and conquer */
    /* firstly, pushdown root tag to children */
    pushdown(root, curStart, curEnd);
    /* then recursively divide and conquer */
    const size_t curMid = mid(curStart, curEnd);
    /* left child tree */
    if(curMid >= start)
        intervalUpdateImpl(start, end, val, ls(root), curStart, curMid);
    /* right child tree */
    if(curMid + 1 <= end)
        intervalUpdateImpl(start, end, val, rs(root), curMid + 1, curEnd);
    /* update root */
    pushup(root);
}
template <typename T>
T SegTree<T>::getIntervalSumImpl(const size_t start, const size_t end,
                                 const size_t root, const size_t curStart,
                                 const size_t curEnd) {
    assert(curStart <= curEnd);

    /* query interval complete cover cur node interval, return tree[root]
    start <= curStart and curEnd <= end */
    if(start <= curStart and curEnd <= end) { return tree[root]; }
    /* not complete cover */
    pushdown(root, curStart, curEnd);
    T res = 0;
    const size_t curMid = mid(curStart, curEnd);
    if(curMid >= start)
        res += getIntervalSumImpl(start, end, ls(root), curStart, curMid);
    if(curMid + 1 <= end)
        res += getIntervalSumImpl(start, end, rs(root), curMid + 1, curEnd);
    return res;
}
template <typename T>
T SegTree<T>::getIntervalSum(const size_t start, const size_t end) {
    return getIntervalSumImpl(start, end, mRoot, mRootStart, mRootEnd);
}
bool debug = true;

void testSegTree() {
    vector<int> arr = { 0, 1, 2, 3, 4, 5, 6 };
    SegTree<int> segtree(arr);
    function<void(const size_t start, const size_t end, bool debug)>
        testIntervalSum;
    function<void(const size_t start, const size_t end, const int val)>
        testIntervalUpdate;

    testIntervalSum = [&arr, &segtree](const size_t start, const size_t end,
                                       bool debug) {
        auto stdAns = accumulate(arr.begin() + start, arr.begin() + end + 1, 0);
        auto stAns = segtree.getIntervalSum(start, end);
        if(stdAns != stAns) { cout << "wrong ans!" << endl; }
        if(debug) {
            cout << "test Interval Sum: [" << start << ", " << end << "]"
                 << endl;
            cout << "Standerd Ans: " << stdAns << endl;
            cout << "SegTree Ans " << stdAns << endl;
        }
    };
    for(int s = 1; s <= arr.size(); s++) {
        for(int e = s; e <= arr.size(); e++) { testIntervalSum(s, e, false); }
    }

    testIntervalUpdate = [&arr, &segtree, testIntervalSum](const size_t start,
                                                           const size_t end,
                                                           const int val) {
        //
        for(int i = start; i <= end; i++) { arr[i] += val; }
        cout << "arr: " << endl;
        for(int i = 0; i < arr.size(); i++) { cout << arr[i] << " "; }
        cout << endl;
        segtree.intervalUpdate(start, end, val);
        testIntervalSum(start, end, true);
    };
    testIntervalUpdate(1, 2, 5);
    testIntervalUpdate(1, 3, -2);
    testIntervalUpdate(2, 2, 1);
    testIntervalUpdate(5, 5, -3);
}

typedef uint64_t ull;
typedef int64_t ll;

const int N = 1e5 + 10;
size_t n, m;
vector<ll> arr(N);

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) { cin >> arr[i]; }
    arr.resize(n + 1);
    SegTree<ll> segtree(arr);
    while(m--) {
        int q, x, y;
        cin >> q;
        if(q == 1) {
            /* 1 x y k */
            ll k;
            cin >> x >> y >> k;
            segtree.intervalUpdate(x, y, k);
        } else if(q == 2) {
            cin >> x >> y;
            cout << segtree.getIntervalSum(x, y) << endl;
        } else {
            assert(false);
        }
    }

    return 0;
}