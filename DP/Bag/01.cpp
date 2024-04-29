#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXV = 1005;

int f[MAXN][MAXV];

int N, V, v, w;

int main() {
    cin >> N >> V;
    // cout << N << V;
    for (int i = 1; i <= N; i++) {
        cin >> v >> w;
        for (int j = 1; j <= V; j++) {
            f[i][j] = f[i-1][j];
            if (j < v) continue;
            f[i][j] = max(f[i-1][j], f[i-1][j - v] + w);
        }
    }
    cout << f[N][V];
    // cout << endl;
    // for (int i = 0; i <=N; i++) {
    //     for(int j = 0; j<= V; j++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

