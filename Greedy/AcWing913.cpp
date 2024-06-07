/*
排队打水
排序不等式

有 n 个人排队到 1个水龙头处打水，第 i 个人装满水桶所需的时间是 ti，
请问如何安排他们的打水顺序才能使所有人的等待时间之和最小？

输入样例：
7
3 6 1 4 2 5 7
输出样例：
56

贪心, 最慢的人放在最前面
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int t[MAXN];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    sort(t + 1, t + 1 + n);
    uint64_t res = 0;
    for(int i = 1; i <= n; i++) {
        res += t[i] * (n - i);
    }
    cout << res << endl;
}