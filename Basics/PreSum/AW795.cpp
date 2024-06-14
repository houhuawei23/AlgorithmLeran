#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];  // 前缀和的初始化

    while(m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);  // 区间和的计算
    }

    return 0;
}

/*
作者：yxc
链接：https://www.acwing.com/activity/content/code/content/39796/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/