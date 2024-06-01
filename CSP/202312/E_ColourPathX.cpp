/*
状态压缩dp + 双向搜索
作者：鱼香猫猫头
链接：https://www.acwing.com/solution/content/229273/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define u1 (u << 1)
#define u2 (u << 1 | 1)
const int N = 100 + 10, MM = 5000 + 10, K = 15;
const int mod = 998244353;
const double eps = 1e-6;
int n, m, k, L, c[N];
vector<pii> g[N], gg[N];
int U[MM], V[MM];
map<int, int> dp[N], dpp[N];
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> L >> k;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 1; i <= m; ++i)
        cin >> U[i];
    for (int i = 1; i <= m; ++i)
        cin >> V[i];
    for (int i = 1; i <= m; ++i) {
        int w;
        cin >> w;
        g[U[i]].push_back(make_pair(V[i], w));
        gg[V[i]].push_back(make_pair(U[i], w));
    }
    L--;
    int l1 = L / 2;
    int l2 = L - l1;
    dp[0][1 << c[0]] = 0;
    for (int _ = 1; _ <= l1; ++_) {
        for (int u = 0; u < n; ++u) {
            for (auto it = dp[u].begin(); it != dp[u].end(); ++it) {
                int mask = it->first;
                if (__builtin_popcount(mask) != _)
                    continue;
                for (pii t : g[u]) {
                    int v = t.first;
                    int w = t.second;
                    if (mask & (1 << c[v]))
                        continue;
                    dp[v][mask | (1 << c[v])] =
                        max(dp[v][mask | (1 << c[v])], dp[u][mask] + w);
                }
            }
        }
    }
    dpp[n - 1][1 << c[n - 1]] = 0;
    for (int _ = 1; _ <= l2; ++_) {
        for (int u = n - 1; u >= 0; --u) {
            for (auto it = dpp[u].begin(); it != dpp[u].end(); ++it) {
                int mask = it->first;
                if (__builtin_popcount(mask) != _)
                    continue;
                for (pii t : gg[u]) {
                    int v = t.first;
                    int w = t.second;
                    if (mask & (1 << c[v]))
                        continue;
                    dpp[v][mask | (1 << c[v])] =
                        max(dpp[v][mask | (1 << c[v])], dpp[u][mask] + w);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i].empty() || dpp[i].empty())
            continue;
        vector<pii> p, pp;
        for (auto it = dp[i].begin(); it != dp[i].end(); ++it)
            p.push_back(make_pair(it->second, it->first));
        for (auto it = dpp[i].begin(); it != dpp[i].end(); ++it)
            pp.push_back(make_pair(it->second, it->first));
        sort(p.begin(), p.end(), greater<pii>());
        sort(pp.begin(), pp.end(), greater<pii>());
        for (pii t1 : p) {
            int w1 = t1.first;
            int mask1 = t1.second;
            if (w1 + pp[0].first <= ans)
                break;
            for (pii t2 : pp) {
                int w2 = t2.first;
                int mask2 = t2.second;
                if (w1 + w2 <= ans)
                    break;
                if ((mask1 & mask2) == (1 << c[i]))
                    ans = max(ans, w1 + w2);
            }
        }
    }
    cout << ans;
    return 0;
}
