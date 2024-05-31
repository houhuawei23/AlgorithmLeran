#include <bits/stdc++.h>
using namespace std;

bool debug = false;
const int MAXN = 1005;

int N;

int arr[MAXN];
int dp[MAXN];
int alast[MAXN];
void printAlast() {
    cout << "alast: " << endl;
    // for (int i = 0; i <= N; i++) {
    //     cout <<  << " ";
    // }
    for (int i = 0; i <= N; i++) {
        cout << alast[i] << " ";
    }
    cout << endl;
}
void printDp() {
    cout << "dp: " << endl;
    // for (int i = 0; i <= N; i++) {
    //     cout <<  << " ";
    // }
    for (int i = 0; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int maxDp(int i) {
    /* 1...i max */
    int maxdp = INT32_MIN;
    for (int j = 1; j <= i; j++) {
        maxdp = max(maxdp, dp[j]);
    }
    return maxdp;
}
int maxDpIndex(int i) {
    /* 1...i max */
    // cout << "maxDpIndex: " << i << endl;
    int maxdpidx = 0;
    for (int j = 1; j <= i; j++) {
        if (dp[j] > dp[maxdpidx]) {
            maxdpidx = j;
        } else if (dp[j] == dp[maxdpidx]) {
            maxdpidx = arr[j] < arr[maxdpidx] ? j : maxdpidx;
        }
    }
    return maxdpidx;
}
int continueDp(int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (arr[i] > arr[j]) {
            return dp[j];
        }
    }
    assert(false);
}
int continueDpIndex(int i) {
    // cout << "continueDpIndex: " << i << endl;
    // cout << "arr[i]: " << arr[i] << endl;
    for (int j = i - 1; j >= 0; j--) {
        if (arr[i] > alast[j]) {
            return j;
        }
    }
    assert(false);
}

int main() {
    cin >> N;
    arr[0] = INT32_MIN;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    /* init */
    alast[0] = INT32_MIN;
    // alast[1] = INT32_MIN;
    int tmp = INT32_MIN;
    for (int i = 1; i <= N; i++) {
        // cout << "arr[" << i << "]: " << arr[i] << endl;
        if (arr[i] > tmp) {
            dp[i] = dp[i - 1] + 1;
            alast[i] = arr[i];
            tmp = arr[i];
            ;
        } else {
            // int maxdp = maxDp(i - 1);
            // int continuedp = continueDp(i);
            int maxdpidx = maxDpIndex(i - 1);
            int continuedpidx = continueDpIndex(i);
            if (debug) {
                cout << "maxdpidx: " << maxdpidx << endl;
                cout << "continuedpidx: " << continuedpidx << endl;
            }
            int lastidx;
            if (dp[maxdpidx] == dp[continuedpidx] + 1) {
                // cout << "==" << endl;
                /* dp max = dp con + 1
                ** choose arr[i] smallest */
                lastidx = arr[maxdpidx] < arr[continuedpidx] ? maxdpidx : i;
                dp[i] = arr[maxdpidx] < arr[continuedpidx]
                            ? dp[maxdpidx]
                            : dp[continuedpidx] + 1;
                tmp = arr[lastidx];
                alast[i] = tmp;
            } else {
                // cout << "!=" << endl;
                dp[i] = max(dp[maxdpidx], dp[continuedpidx] + 1);
                tmp = dp[maxdpidx] > dp[continuedpidx] + 1 ? alast[maxdpidx]
                                                           : arr[i];
                alast[i] = tmp;
            }
        }
        // cout << "alast: " << tmp << endl;
    }
    // printDp();
    // printAlast();
    cout << dp[N];
}

/*
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/