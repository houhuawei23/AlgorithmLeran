/*
货仓选址
在一条数轴上有 N家商店，它们的坐标分别为 A1 ∼ AN。

现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。

为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。

输入样例：
4
6 2 9 1
输出样例：
12

first think a simple question:
min[x] |a - x| + |b - x|
off course, a <= min_x <= b
for min[q] Sum[i=1...n] |xi - q|, q must in all the pair(xi, xn-i)
so, if n is even, x can be (xn/2-1, xn/2)
if n in odd, x must be xn/2
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int n, res;
int a[MAXN];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n / 2; i++) {
        res += a[n - i - 1] - a[i];
        /*
        n % 2 == 0
        0 ~ n/2
        n = 6, n/2=3, i=0,1,2
        n = 7, n/2=3, i=0,1,2 4,5,6, jump 3, becase 3 is mid number, delta = 0
        */
    }
    /*
    or
    for(int i = 0; i<n; i++) {
        res += abs(a[i] - a[n/2]);
    }
    */
    cout << res << endl;
}
