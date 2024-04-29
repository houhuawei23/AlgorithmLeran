#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXV = 1005;

/*

f[i][j] = f[i-1][j]                     取 0 个 i
f[i][j] = max(f[i][j], f[i][j-v] + w)   取 k 个 i

i=2,j=2
f22 = f12 = 4
f22 = max(f22, f20 + 4)

f23 = f13 = 6
f23 = max(f23, f21 + 4)

  0 1 2 3 4 5
0 0 0 0 0 0 0 
1 0 2 4 6 8 10
2 0 2 4 6 8 10
3 0 2 
4
*/

int f[MAXN][MAXV];

int N, V, v, w;

int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> v >> w;
        for (int j = 1; j <= V; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v) {
                f[i][j] = max(f[i][j], f[i][j - v] + w);
            }
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     cin >> v >> w;
    //     for (int j = 0; j <= V; j++) {
    //         f[i][j] = f[i - 1][j];
    //         for (int k = 0; k * v <= j; k++) {
    //             f[i][j] = max(f[i][j], f[i-1][j - k * v] + k * w);
    //         }
    //     }
    // }

    cout << f[N][V];
    // cout << endl;
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= V; j++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
