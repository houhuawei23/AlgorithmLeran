#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
int f[N][N];
int v, w;

int main(){
    cin >> n >> m;
    for (int i = 1; i <=n; i++){
        cin >> v >> w;
        
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i-1][j];
            if (j >= v) {
                f[i][j] = max(f[i][j], f[i-1][j-v] + w);
            }
        }
        // wrong ans
        // for (int j = v; j <= m; j++) {
            // f[i][j] = max(f[i-1][j], f[i-1][j-v] + w);
        // }
    }
    
    cout << f[n][m] << endl;
    for (int i=0; i<=n; i++){
        for (int j=0;j<=m;j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
