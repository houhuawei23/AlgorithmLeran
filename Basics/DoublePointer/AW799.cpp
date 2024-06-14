#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], s[N];
// 数组s是为了记录范围，当q数组中出现相同的元素值的时候，
// 就会出现s[q[i]]大于一，也就是判断这段数字有没有重复的标志

int main() {
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)
        scanf("%d", &q[i]);
    int res = 0;  // 用来返回最大值
    for(int i = 0, j = 0; i < n; i++) {
        s[q[i]]++;  // 将右端点往右移动一格
        // 由于上边的自增，导致这个s数组中的元素可能会出现了大于1的情况，这时候就要去重
        while(s[q[i]] > 1)
            s[q[j++]]--;
        // 这一步的作用就是将左端点往右移动，同时，
        // 让这个s数组中元素大于1的，都减去1，这样可以去重
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
