#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1005;
const int VMAX = 1e6 + 5;
int v[NMAX], w[NMAX];

int f[VMAX];

int main(){
    int N, V; cin >> N >> V;
    for (int i = 1; i <= NMAX; i++){
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= N; i++){
        for (int j = v[i]; j <= V; j++){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
}