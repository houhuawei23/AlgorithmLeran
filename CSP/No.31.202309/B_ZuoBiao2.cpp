#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

typedef pair<int, double> OP;

OP ops[N];
int n, m;
double pk[N];
double pt[N];
double res[N][2];
int main() {
    cin >> n >> m;
    pk[0]=1;
    for (int i = 1; i <= n; i++) {
        // cin >> ops[i].first >> ops[i].second;
        int opcode;
        double op;
        cin >> opcode >> op;
        if (opcode == 1) {
            pk[i] = pk[i - 1] * op;
            pt[i] = pt[i - 1];
        } else if (opcode = 2) {
            pk[i] = pk[i - 1];
            pt[i] = pt[i - 1] + op;
        } else {
            assert(false);
        }
    }
    // cout << "\npk: ";
    // for (int i = 0; i <= n; i++) {
    //     cout << pk[i] << " ";
    // }
    // cout << "\npt: ";
    // for (int i = 0; i <= n; i++) {
    //     cout << pt[i] << " ";
    // }
    int i, j;
    double x, y;
    for (int ii = 1; ii <= m; ii++) {
        cin >> i >> j >> x >> y;
        double kk = pk[j] / pk[i - 1];
        double tt = pt[j] - pt[i - 1];
        double tx = kk * x;
        double ty = kk * y;
        double xx = tx * cos(tt) - ty * sin(tt);
        double yy = tx * sin(tt) + ty * cos(tt);
        res[ii][0] = xx;
        res[ii][1] = yy;
    }

    for (int i = 1; i <= m; i++) {
        printf("%.3lf %.3lf\n", res[i][0], res[i][1]);
        // cout << res[i][0] << " " << res[i][1] <<endl;
    }
}

/*
输入样例：
10 5
2 0.59
2 4.956
1 0.997
1 1.364
1 1.242
1 0.82
2 2.824
1 0.716
2 0.178
2 4.094
1 6 -953188 -946637
1 9 969538 848081
4 7 -114758 522223
1 9 -535079 601597
8 8 159430 -511187
输出样例：
-1858706.758 -83259.993
-1261428.46 201113.678
-75099.123 -738950.159
-119179.897 -789457.532
114151.88 -366009.892
*/