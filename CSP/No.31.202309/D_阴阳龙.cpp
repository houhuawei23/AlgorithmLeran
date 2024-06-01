#include <bits/stdc++.h>

using namespace std;

// const int N = 1e9+2;
const int N = 1e3 + 2;
const int P = 1e5 + 2;

int posx[P], posy[P];  // p 个人的位置
int tmp[P];            // index of di
//           0  1  2   3   4   5   6   7
int Dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int Dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};  //

int main() {
    // n*m 棋盘大小 1e9， p个员工，q次探查 1e5
    //
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    int u, v, t;  // 龙的位置
    for (int i = 1; i <= p; i++) {
        cin >> posx[i] >> posy[i];
    }
    for (int i = 1; i <= q; i++) {
        // 第i次探查，每次探查后都要更新所有员工的位置
        cin >> u >> v >> t;
        // 计算出 k
        // K1
        int mink1 = INT_MAX;
        // 遍历所有的员工，1在8个方位上 2计算距离 3更新mink1
        for (int j = 1; j <= p; j++) {
            // abs(posx[j] - u) == abs(posy[j] - v)
            int adx = abs(posx[j] - u);
            int ady = abs(posy[j] - v);

            if (((!adx || !ady) || (adx == ady)) && (adx || ady)) {
                // cout << "ad: " << adx << ", " << ady << endl;
                mink1 = min(mink1, max(adx, ady));
                // tmp
                int dx = posx[j] - u;
                int dy = posy[j] - v;
                if (dx > 0 && dy == 0)
                    tmp[j] = 0;
                else if (dx > 0 && dy > 0)
                    tmp[j] = 1;
                else if (dx == 0 && dy > 0)
                    tmp[j] = 2;
                else if (dx < 0 && dy > 0)
                    tmp[j] = 3;
                else if (dx < 0 && dy == 0)
                    tmp[j] = 4;
                else if (dx < 0 && dy < 0)
                    tmp[j] = 5;
                else if (dx == 0 && dy < 0)
                    tmp[j] = 6;
                else if (dx > 0 && dy < 0)
                    tmp[j] = 7;
                // cout << "tmp[j]: " << tmp[j] << endl;
            }
        }
        // cout << "mink1: " << mink1 << endl;
        // K2
        int k2 = min({n - u, m - v, u, v});
        int k = 0;
        if (mink1 <= k2) {
            k = mink1;
        }
        // cout << "k2, k: " << k2 << ", " << k << endl;
        if (k > 0) {  // 更新所有（8各方位上k距离处的）员工的位置

            // 遍历所有
            for (int j = 1; j <= p; j++) {
                // abs(posx[j] - u) == abs(posy[j] - v)

                int adx = abs(posx[j] - u);
                int ady = abs(posy[j] - v);

                if (((!adx || !ady) || (adx == ady)) && (adx || ady) &&
                    (max(adx, ady) == k)) {
                    // cout << "ad: " << adx << ", " << ady << endl;
                    // cout << "pos: " << posx[j] << ", " << posy[j] << endl;
                    // 变换
                    // cout << "pos: (" << posx[j] << ", " << posy[j] << ") ->
                    // ";
                    int Di = (tmp[j] + t) % 8;
                    posx[j] = u + Dx[Di] * k;
                    posy[j] = v + Dy[Di] * k;

                    // cout << "(" << posx[j] << ", " << posy[j] << ")" << endl;
                }
            }
        }

    }  // 第i次探查结束
    int res = posx[1] + posy[1];
    for (int i = 2; i <= p; i++) {
        res ^= i * posx[i] + posy[i];
    }
    cout << res;
    return 0;
}