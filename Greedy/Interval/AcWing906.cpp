/* 区间分组

给定 N 个闭区间 [ai,bi]，请你将这些区间分成若干组，
使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。

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
} ranges[MAXN];

void print_ranges() {
    for (int i = 0; i <= N; i++) {
        auto& range = ranges[i];
        cout << i << ": (" << range.l << ", " << range.r << ")\n";
    }
}

int solveVector() {
    vector<int> maxR;
    auto print_maxR = [&]() {
        cout << "maxR: " << endl;
        for (auto r : maxR) {
            cout << r << " ";
        }
        cout << endl;
    };
    for (int i = 1; i <= N; i++) {
        // print_maxR();
        auto& rg = ranges[i];
        bool putin = false;
        for (auto& maxr : maxR) {
            if (rg.l > maxr) { /* not insertion */
                maxr = rg.r;
                putin = true;
                break;
            }
        }
        if (not putin) {
            /* new group */
            maxR.push_back(rg.r);
        }
    }
    // print_maxR();
    return maxR.size();
}

int solvePQueue() {
    /* little heap */
    priority_queue<int, vector<int>, greater<int>> maxR;
    auto print_maxR = [&]() {
        auto copy = maxR;
        cout << "maxR: " << endl;
        while (!copy.empty()) {
            cout << copy.top() << " ";
            copy.pop();
        }
        cout << endl;
    };
    for (int i = 1; i <= N; i++) {
        // print_maxR();
        auto& rg = ranges[i];
        if (maxR.empty() || maxR.top() >= rg.l) {
            /* insertion for all, new group */
            maxR.push(rg.r);
        } else {
            /* update */
            maxR.pop();
            maxR.push(rg.r);
        }
    }
    // print_maxR();
    return maxR.size();
}

/*
1. sort ranges by left point in acseding
2. from left to right

*/

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> ranges[i].l >> ranges[i].r;
    }
    // print_ranges();
    sort(ranges + 1, ranges + 1 + N,
         [&](Range& lhs, Range& rhs) { return lhs.l < rhs.l; });
    // print_ranges();
    int res = solvePQueue();
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