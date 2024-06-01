#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int M = 12;

int ku[N][M];

int main() {
    int n, m; cin>>n>>m;
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= m; j++) {
            cin >> ku[i][j];
        }
    }
}