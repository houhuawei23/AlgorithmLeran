/*
241. 楼兰图腾
n <= 2e5

n
y1, y2, ..., yn

输入样例：
5
1 5 3 2 4
输出样例：
3 4
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

typedef uint64_t ull;
#define lowbit(x) ((x) & -(x))

int n;
int a[N];
/*
from left to right
Lower[i]: num of point j that yj < yi (yj in [1 ~ yi - 1]) and j < i
*/
// int Lower[N], Greater[N];

/*
arr[i] = 1, if has meet i
so sum(l, r) calculate num of point that l <= j <= r
use bit to cal sum
*/
struct BIT {
    int tree[N];
    void update(int x, int d) {
        for(int i = x; i <= n; i += lowbit(i)) tree[i] += d;
    }
    int preSum(int x) {
        int sum = 0;
        for(int i = x; i; i -= lowbit(i)) sum += tree[i];
        return sum;
    }
    int sum(int l, int r) { return preSum(r) - preSum(l - 1); }
} bit;
struct BITree {
    vector<int> tree;
    BITree(const vector<int>& init) : tree(init.size()) {
        for(int i = 1; i <= init.size(); i++) { update(i, init[i]); }
    }
    void update(int x, int d) {
        for(int i = x; i <= n; i += lowbit(i)) tree[i] += d;
    }
    int preSum(int x) {
        int sum = 0;
        for(int i = x; i; i -= lowbit(i)) sum += tree[i];
        return sum;
    }
    int sum(int l, int r) { return preSum(r) - preSum(l - 1); }
};

ull numV, numA;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) { cin >> a[i]; }
    for(int i = 1; i <= n; i++) {
        int yi = a[i];
        auto Lower = bit.preSum(yi - 1);   /* for A */
        auto Greater = bit.sum(yi + 1, n); /* for V */

        numA += (ull)Lower * (yi - 1 - Lower);
        numV += (ull)Greater * (n - yi - Greater);
        bit.update(yi, 1);
    }
    cout << numV << " " << numA << endl;
    return 0;
}
