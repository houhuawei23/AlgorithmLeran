/*
f[i][j] = max(f[i-1][j - v[i] * k] + w[i] * k) 
k = 0, 1, 2, ..., s[i]
1000*2000*2000
4e9
for k from 0 to s: regardless kv<=j
f[i][j] = max(f[i-1][j], f[i-1][j-v]+w, f[i-1][j-2v]+2w, ..., f[i-1][j-sv]+sw)
f[i][j-v] = max(         f[i-1][j-v],   f[i-1][j-2v]+w,  ..., f[i-1][j-sv]+(s-1)w, f[i-1][j-(s+1)v]+sw)
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int VMAX = 25000;

int f[VMAX];
// int v[N], w[N], s[N];
int v[VMAX], w[VMAX];

int v0, w0, s0;

int main(){
    int n, m; cin >>n >> m;
    int nn = 0;
    /* construct v, w
    for (int i = 1; i<=n; i++)
    {   
        // v, w, s
        cin >> v0 >> w0 >> s0;
        // 拆
        int j = 1;
        for (; 2*j-1 < s0; j*=2) {
            nn++;
            v[nn] = j * v0;
            w[nn] = j * w0;
        }
        nn++;
        int c = s0 - (j - 1);
        v[nn] = c * v0;
        w[nn] = c * w0;
    }
    */
    for (int i = 1; i<=n; i++)
    {   
        // v, w, s
        cin >> v0 >> w0 >> s0;
        // 拆
        int k = 1;
        while(k <= s0){
            nn++;
            v[nn] = k * v0;
            w[nn] = k * w0;
            s0 -= k;
            k*=2;
        }
        if (s0 > 0) {
            nn++;
            v[nn] = s0 * v0;
            w[nn] = s0 * w0;
        }

    }

    for (int i = 1; i <= nn; i++){
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m];
    
}

