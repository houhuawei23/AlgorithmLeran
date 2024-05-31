/*
最大不相交区间数量
输入样例：
3
-1 1
2 4
3 5
输出样例：
2
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int N;

struct Range {
    int l, r;
    bool operator<(const Range& rhs) const { return r < rhs.r; }

} ranges[MAXN];

void print_ranges() {
    for (int i = 0; i <= N; i++) {
        auto& range = ranges[i];
        cout << i << ": (" << range.l << ", " << range.r << ")\n";
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> ranges[i].l >> ranges[i].r;
    }
    // print_ranges();
    sort(ranges + 1, ranges + 1 + N);
    // cout << "sorted: " << endl;
    // print_ranges();
    int res = 0, ed = -2e9;
    for (int i = 1; i <= N; i++) {
        auto& rg = ranges[i];
        if (ed < rg.l) {
            res++;
            ed = rg.r;
        }
    }
    cout << res << endl;
}

/*
输入样例：
3
2 4
3 5
-1 1

输出样例：
2
*/