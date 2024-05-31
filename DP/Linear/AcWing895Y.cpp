#include <bits/stdc++.h>
using namespace std;

bool debug = false;
const int MAXN = 1005;

int N;

int a[MAXN];
int dp[MAXN];

void print_dp() {
    for (int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

/*
dp[i]: 
set:
    set of strict ascending sub-seq end with a[i]
attribute:
    max length of sub-seq
cal:
dp[i] = max(dp[j]), j in [1...i-1]
s.t. a[i] > a[j]

*/
int solve() {
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        dp[i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int maxLen = INT32_MIN;
    for (int i = 1; i <= N; i++) {
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int main() {
    cin >> N;
    int maxLen = solve();
    // print_dp();
    cout << maxLen << endl;
}
/*
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/