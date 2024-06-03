/*
最长上升子序列 II
https://www.acwing.com/problem/content/898/
N = 1e5
DP: O(N^2) 超时

*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN];
// int stk[MAXN];
int N;

/*
stk[i]:
in all the ascending sub-seq of arr with the length of i,
the min end element is stk[i]
stk is ascending

next a:
if a > stk.back():
    a > max, a can append to stk.back(), let sub-seq extend
else:
    a must insert into stk[i], where stk[i] >= a, left most
    greedy

题解中最难理解的地方在于栈中序列虽然递增，但是每个元素在原串中对应的位置其实可能是乱的，
那为什么这个栈还能用于计算最长子序列长度？
实际上这个栈【不用于记录最终的最长子序列】，而是【以stk[i]结尾的子串长度最长为i】或者说
【长度为i的递增子串中，末尾元素最小的是stk[i]】。
理解了这个问题以后就知道为什么新进来的元素要不就在末尾增加，要不就替代第一个大于等于它元素的位置。
这里的【替换】就蕴含了一个贪心的思想，对于同样长度的子串，
我当然希望它的末端越小越好，这样以后我也有更多机会拓展。
*/
int solve() {
    vector<int> stk;
    stk.push_back(a[1]);

    for (int i = 2; i <= N; i++) {
        if (a[i] > stk.back()) {
            stk.push_back(a[i]);
        } else {
            // a[i] <= stk.back()
            /* find first element that >= a[i] */
            auto iter = lower_bound(stk.begin(), stk.end(), a[i]);
            assert(iter != stk.end()); /* must can find */
            *iter = a[i];
        }
    }
    return stk.size();
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    cout << solve() << endl;
}

/*
作者：233
链接：https://www.acwing.com/solution/content/3783/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
int solve233() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> stk;  // 模拟堆栈
    stk.push_back(arr[0]);

    for (int i = 1; i < n; ++i) {
        // 如果该元素大于栈顶元素,将该元素入栈
        if (arr[i] > stk.back())
            stk.push_back(arr[i]);
        else  // 替换掉第一个大于或者等于这个数字的那个数
            *lower_bound(stk.begin(), stk.end(), arr[i]) = arr[i];
    }
    cout << stk.size() << endl;
    return 0;
}