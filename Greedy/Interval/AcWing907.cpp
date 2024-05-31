/* 区间覆盖 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int N;
int s, t;
struct Range {
    int l, r;
} ranges[MAXN];

void print_ranges() {
    for (int i = 0; i <= N; i++) {
        auto& range = ranges[i];
        cout << i << ": (" << range.l << ", " << range.r << ")\n";
    }
}
/*
1. left point sort asceding
2. from left to right, in the ranges of cover start,
    choose right endpoint largest range
    - then update start = largest right endpoint
*/

int solve() {
    int start = s;
    int res = 0;
    for (int i = 1; i <= N; i++) {
        int j = i, r = -2e9;
        while (j <= N && ranges[j].l <= start) {
            r = max(r, ranges[j].r);
            j++;
        }
        if (r < start) {
            return -1;
        }
        res++;
        if (r >= t) {
            return res;
        }
        start = r;
        i = j - 1;
    }
    return -1;
}

int main() {
    cin >> s >> t;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> ranges[i].l >> ranges[i].r;
    }
    // print_ranges();
    sort(ranges + 1, ranges + 1 + N,
         [&](Range& lhs, Range& rhs) { return lhs.l < rhs.l; });
    // print_ranges();
    int res = solve();
    cout << res << endl;
}

/*
输入样例：
1 5
3
-1 3
2 4
3 5
输出样例：
2
*/