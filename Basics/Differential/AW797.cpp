#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= n; i++)
        insert(i, i, a[i]);

    while(m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for(int i = 1; i <= n; i++)
        b[i] += b[i - 1];

    for(int i = 1; i <= n; i++)
        printf("%d ", b[i]);

    return 0;
}

/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/39799/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/