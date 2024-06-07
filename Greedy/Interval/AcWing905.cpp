/*
给定 N个闭区间 [ai,bi] 请你在数轴上选择尽量少的点，
使得每个区间内至少包含一个选出的点。输出选择的点的最小数量。
输出可选取区间的最大数量。

输入样例：
3
-1 1
2 4
3 5
输出样例：
2

Proof: ? ans == cnt
1. ans <= cnt
2. ans >= cnt

*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int N;

struct Range {
    int l, r;
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
    sort(ranges + 1, ranges + 1 + N,
         [&](Range lhs, Range rhs) { return lhs.r < rhs.r; });
    // print_ranges();
    int res = 0, right = -2e9;
    for (int i = 1; i <= N; i++) {
        if (right < ranges[i].l) {
            res++;
            right = ranges[i].r;
        }
    }
    cout << res << endl;
    return 0;
}

/*
test sort
3
2 4
3 5
-1 1

*/