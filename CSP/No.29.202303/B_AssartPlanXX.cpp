/*
100/100
-
70分思路是对每一个区域单独处理，仔细分析后，发现可以对同一基础耗时的区域同时处理
- 单独开一个数组sa用来记录同一基础耗时的区域所需资源总数
- 从mx到k依次处理，每次使得最大基础耗时的区域同时减少一天
- 同一基础耗时的区域可以视作一个区域, 要想使MaxDay减小,
    必须同时使所有的同基础耗时区域都减少
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m, k;
int t[N], c[N];
int sa[N];  // 记录同一基础耗时缩减一天所需要的总资源
int mx;     // 记录基础耗时的最大值

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        sa[t[i]] += c[i];  // 记录同一基础耗时缩减一天所需要的总资源
        mx = max(mx, t[i]);
    }
    int ans = mx;  // 记录结果
    for (int i = mx; i >= k; i--) {
        if (sa[ans] > m)
            break;
        m -= sa[ans];            // 同一基础耗时的同时减少一天
        sa[ans - 1] += sa[ans];  // 下一天的需要加上上一天的资源总数
        // ans的最小值为k
        if (ans > k) {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
