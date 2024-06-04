/*
二进制优化 DP
f[i][j] = max(f[i-1][j - v[i] * k] + w[i] * k)
k = 0, 1, 2, ..., s[i]
1000*2000*2000
4e9
for k from 0 to s: regardless kv<=j
f[i][j] = max(f[i-1][j], f[i-1][j-v]+w, f[i-1][j-2v]+2w, ..., f[i-1][j-sv]+sw)
f[i][j-v] = max(         f[i-1][j-v],   f[i-1][j-2v]+w,  ...,
f[i-1][j-sv]+(s-1)w, f[i-1][j-(s+1)v]+sw)

*/

#include <bits/stdc++.h>
using namespace std;

const int MAXNEWN = 1000 * 11 + 10;
const int MAXV = 2010;

struct Item {
    int v, w;
};

int N, V;
Item goods[MAXNEWN];
// int dp[MAXNEWN][MAXV]; /* 1e4 * 2e3 = 2e7 */
int f[MAXV];

// void print_dp(int n, int v) {
//     cout << "== dp ==" << endl;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= v; j++) {
//             cout << dp[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
void print_goods(int n) {
    cout << "== goods == " << endl;
    cout << "v  w" << endl;
    for (int i = 1; i <= n; i++) {
        auto& g = goods[i];
        cout << g.v << " " << g.w << endl;
    }
}
int main() {
    cin >> N >> V;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        /* split each item into binary representation */
        int k = 1;
        while (k < s) {
            cnt++;
            goods[cnt].v = k * v;
            goods[cnt].w = k * w;
            s -= k;
            k *= 2;
        }
        if (s > 0) {
            cnt++;
            goods[cnt].v = s * v;
            goods[cnt].w = s * w;
        }
    }
    // print_goods(cnt);
    /* 01 Bag */
    N = cnt;
    // auto dp_origin = [&] {
    //     for (int i = 1; i <= N; i++) {
    //         for (int j = 1; j <= V; j++) {
    //             dp[i][j] = dp[i - 1][j];
    //             if (j >= goods[i].v) {
    //                 dp[i][j] =
    //                     max(dp[i][j], dp[i - 1][j - goods[i].v] + goods[i].w);
    //             }
    //         }
    //     }
    //     cout << dp[N][V] << endl;
    // };
    // dp_origin();

    auto dp_opt = [&] {
        for (int i = 1; i <= N; i++) {
            auto& g = goods[i];
            for (int j = V; j >= g.v; j--) {
                f[j] = max(f[j], f[j - g.v] + g.w);
            }
        }
        cout << f[V] << endl;
    };
    dp_opt();

    // print_dp(N, V);
}
/*
输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/