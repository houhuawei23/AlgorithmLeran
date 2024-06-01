#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int M = 12;

int n, m;
int houses[N][M];
int res[N];

bool check(int base, int up) {
    /* check houses[up] can be the upper of houses[base]*/
    bool allBig = true;
    for (int i = 1; i <= m; i++) {
        if (houses[up][i] <= houses[base][i])
            allBig = false;
    }
    // cout << "check(" << base << ", " << up << ") = " << allBig << endl;
    return allBig;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> houses[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        // int resi = 0;
        for (int j = 1; j <= n; j++) {
            if (j == i)
                continue;
            if (check(i, j)) {
                res[i] = j;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }
}

/*
输入样例：
4 2
0 0
-1 -1
1 2
0 -1
输出样例：
3
1
0
3
*/