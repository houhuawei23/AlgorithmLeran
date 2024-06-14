#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n, m, q;
int matrix[N][N];

int main() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> matrix[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            matrix[i][j] +=
                matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];

    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << matrix[x2][y2] - matrix[x1 - 1][y2] - matrix[x2][y1 - 1] +
                matrix[x1 - 1][y1 - 1]
             << endl;
    }
}