#include <bits/stdc++.h>
using namespace std;

bool debug = false;
const int MAXN = 35;

int a[MAXN];
// bool selects[MAXN];
// vector<bool> select;

int n, x;

int minVal;

int selectCnt = 0;

int calc(const vector<bool>& select) {
    assert(select.size() == n);
    int huafei = 0;
    for (int i = 0; i < n; i++) {
        if (select[i]) {
            huafei += a[i];
        }
    }
    // cout << "huafei: " << huafei << endl;

    return huafei;
}

void print_select(const string& comment, const vector<bool>& select) {
    cout << comment << endl;
    for (auto e : select) {
        cout << e << " ";
    }
    cout << "." << endl;
}
void dfs(vector<bool> select) {
    if (debug) {
        print_select("dfs", select);
    }
    if (select.size() == n) {
        selectCnt++;
        int huafei = calc(select);
        if (huafei < minVal && huafei >= x) {
            /* update minVal */
            minVal = huafei;
        }
        return;
    }
    /* not n */
    auto s1 = vector<bool>(select);
    s1.push_back(0);
    dfs(s1);

    auto s2 = vector<bool>(select);
    s2.push_back(1);
    dfs(s2);
}

int main() {
    cin >> n >> x;
    minVal = INT32_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // calc({1, 1, 1, 1});
    // calc({0, 1, 1, 1});
    // calc({1, 0, 1, 1});
    // calc({1, 1, 0, 1});
    dfs({});
    assert(selectCnt == (1 << n));
    if (debug) {
        cout << "select cnt: " << selectCnt << endl;
    }
    cout << minVal << endl;
}