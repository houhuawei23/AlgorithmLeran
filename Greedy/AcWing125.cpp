/*耍杂技的牛
贪心-推公式

农民约翰的 N 头奶牛(编号为 1..N)
计划逃跑并加入马戏团，为此它们决定练习表演杂技。

奶牛们不是非常有创意，只提出了一个杂技表演：

叠罗汉，表演时，奶牛们站在彼此的身上，形成一个高高的垂直堆叠。

奶牛们正在试图找到自己在这个堆叠中应该所处的位置顺序。

这 N头奶牛中的每一头都有着自己的重量 Wi以及自己的强壮程度 Si。

一头牛支撑不住的可能性取决于它头上所有牛的总重量（不包括它自己）减去它的身体强壮程度的值，
现在称该数值为风险值，风险值越大，这只牛撑不住的可能性越高。

您的任务是确定奶牛的排序，使得所有奶牛的风险值中的最大值尽可能的小。

输入样例：
3
10 3
2 5
3 3
输出样例：
2

wi + si 从小到da排序, 最大危险系数一定最小

*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 10;
int n;
// int w[MAXN],s[MAXN];
typedef pair<int, int> PII;
PII a[MAXN];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        // cin >> w[i] >> w[s];
        int w, s;
        cin >> w >> s;
        a[i] = { w + s, w };
    }
    sort(a, a + n);
    int64_t res = -1e18, sum = 0;
    for(int i = 0; i < n; i++) {
        int w = a[i].second, s = a[i].first - w;
        res = max(res, sum - s);
        sum += w;
    }
    cout << res << endl;
}