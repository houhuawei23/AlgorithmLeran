#include <bits/stdc++.h>
using namespace std;

const int N = 100;
#define lowbit(x) ((x) & -(x))

int tree[N];

void update(int x, int d) {
    /* 单点修改: a[x] += d */
    while(x <= N) {
        tree[x] += d;
        x += lowbit(x); /* father of x */
    }
}
int sum(int x) {
    /* 区间查询: 前缀和 */
    int ans = 0;
    while(x > 0) {
        ans += tree[x];
        x -= lowbit(x); /* next tree[x] */
    }
    return ans;
}

void updateBeta(int x, int d) {
    int n;
    for(int i = x; i <= n; i += lowbit(i)) { tree[i] += d; }
}
int sumBeta(int x) {
    int ans = 0;
    for(int i = x; i; i -= lowbit(i)) { ans += tree[i]; }
    return ans;
}

struct BITree {
    vector<int> tree;
    BITree() = default;
    BITree(const vector<int>& init) : tree(init.size()) {
        for(int i = 1; i <= init.size(); i++) { update(i, init[i]); }
    }
    void update(int x, int d) {
        for(int i = x; i <= tree.size(); i += lowbit(i)) tree[i] += d;
    }
    int preSum(int x) {
        int sum = 0;
        for(int i = x; i; i -= lowbit(i)) sum += tree[i];
        return sum;
    }
    int sum(int l, int r) { return preSum(r) - preSum(l - 1); }
};

void testBITree() {
    vector<int> arr = { -1, 1, 2, 3, 4, 5, 6, 7, 8 };
    BITree bit(arr);
    cout << "presum(5, 8): "
         << accumulate(arr.begin() + 5, arr.begin() + 8 + 1, 0) << endl;
    cout << bit.sum(5, 8) << endl;
    bit.update(6, 20);
    cout << bit.sum(5, 8) << endl;
}
void test() {
    vector<int> arr = { -1, 1, 2, 3, 4, 5, 6, 7, 8 };
    for(int i = 1; i <= arr.size(); i++) { update(i, arr[i]); }
    cout << "presum(5, 8): " << accumulate(arr.begin() + 5, arr.begin() + 8, 0)
         << endl;
    cout << "presum(5, 8): " << sum(8) - sum(5 - 1) << endl;
    update(6, 20);
    cout << "presum(5, 8): " << sum(8) - sum(5 - 1) << endl;
}
int main() {
    testBITree();
    return 0;
}
