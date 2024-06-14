/* 二进制中1的个数
用补码表示负整数，-x = ~x + 1
*/
#include <iostream>

using namespace std;

int cnt(int x) {
    int ans = 0;
    while(x) {
        x &= (x - 1);
        ++ans;
    }
    return ans;
}
/* 
直接去掉末尾的 1
i = i&(i-1)

lowbit
使用lowbit操作，每次lowbit操作截取一个数字最后一个1后面的所有位，
每次减去lowbit得到的数字，直到数字减到0，就得到了最终1的个数，
*/
int lowbit(int x) { return x & (-x); }

int cntOf1(int a) {
    int k = 0;
    while(a) {
        k += a & 1; /* lowest bit */
        a = a >> 1;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int x, s = 0;
        scanf("%d", &x);

        for(int i = x; i; i -= i & -i) s++;

        printf("%d ", s);
    }

    return 0;
}