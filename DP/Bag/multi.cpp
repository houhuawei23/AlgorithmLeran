#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int MAXV = 105;

int f[MAXN][MAXV];

int N, V, v, w, s;

/*
f[i][j] = max(f[i-1][j - v[i] * k] + w[i] * k) 
k = 0, 1, 2, ..., s[i]
*/

int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> v >> w >> s;
        for (int j = 1; j <= V; j++) {
            f[i][j] = f[i - 1][j];
            for (int k = 0; k * v <= j && k <= s; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v] + k * w);
            }
        }
    }
    cout << f[N][V];
    // cout << endl;
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= V; j++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}