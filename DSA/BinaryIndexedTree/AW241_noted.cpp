#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2000010;

typedef long long LL;

int n;
// t[i]表示树状数组i结点覆盖的范围和
int a[N], t[N];
// Lower[i]表示左边比第i个位置小的数的个数
// Greater[i]表示左边比第i个位置大的数的个数
int Lower[N], Greater[N];

// 返回非负整数x在二进制表示下最低位1及其后面的0构成的数值
int lowbit(int x) { return x & -x; }

// 将序列中第x个数加上k。
void add(int x, int k) {
    for(int i = x; i <= n; i += lowbit(i)) t[i] += k;
}
// 查询序列前x个数的和
int ask(int x) {
    int sum = 0;
    for(int i = x; i; i -= lowbit(i)) sum += t[i];
    return sum;
}

int main() {

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    // 从左向右，依次统计每个位置左边比第i个数y小的数的个数、以及大的数的个数
    for(int i = 1; i <= n; i++) {
        int y = a[i];  // 第i个数

        // 在前面已加入树状数组的所有数中统计在区间[1, y - 1]的数字的出现次数
        Lower[i] = ask(y - 1);

        // 在前面已加入树状数组的所有数中统计在区间[y + 1, n]的数字的出现次数
        Greater[i] = ask(n) - ask(y);

        // 将y加入树状数组，即数字y出现1次
        add(y, 1);
    }

    // 清空树状数组，从右往左统计每个位置右边比第i个数y小的数的个数、以及大的数的个数
    memset(t, 0, sizeof t);

    LL resA = 0, resV = 0;
    // 从右往左统计
    for(int i = n; i >= 1; i--) {
        int y = a[i];
        resA += (LL)Lower[i] * ask(y - 1);
        resV += (LL)Greater[i] * (ask(n) - ask(y));

        // 将y加入树状数组，即数字y出现1次
        add(y, 1);
    }

    printf("%lld %lld\n", resV, resA);

    return 0;
}
/*

作者：qiaoxinwei
链接：https://www.acwing.com/solution/content/13818/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/