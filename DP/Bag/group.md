```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int v[N][N], w[N][N];
int s[N];
int f[N][N];

int main(){
    int n, m; cin>>n>>m;
     for (int i = 1; i <= n; i++) {
         cin >> s[i];
         for (int j = 1; j <= s[i]; j++) {
             cin >> v[i][j] >> w[i][j];
         }
     }
     for (int i = 1; i <= n; i++) {
         for (int j = 0; j <= m; j++) {
             f[i][j] = f[i-1][j];
             for (int k = 1; k <= s[i]; k++) {
                 if (j >= v[i][k]){
                     f[i][j] = max(f[i][j], f[i-1][j - v[i][k]] + w[i][k]);
                 }
                 
             }
         }
     }
     cout << f[n][m] << endl;
}
```

