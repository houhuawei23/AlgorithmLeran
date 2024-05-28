/*
biSearch minMaxDay in [k, mx], use judge() to judge 
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m, k;
int t[N], c[N];
int mx;  // 记录最大天数

// 判断当前耗时天数x能否满足需求
bool jude(int x) {
    int sum = 0;  // 记录资源总和
    for (int i = 1; i <= n; i++) {
        if (t[i] < x)
            continue;  // 基础耗时小于x，不需要考虑资源消耗
        sum += (t[i] - x) * c[i];  // sum的值进行改变
        if (sum > m)
            return false;  // 如果资源总和大于m，不满足条件
    }
    return true;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        mx = max(mx, t[i]);
    }
    int l = k, r = mx;  // 二分：左边起点为l，右边为mx
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (jude(mid))
            r = mid - 1;  // 满足条件，往小范围搜索
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
