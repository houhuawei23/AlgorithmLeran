#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

int main() {
    scanf("%d%d%d", &n, &m, &x);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for(int i = 0, j = m - 1; i < n; i++) {
        while(j >= 0 && a[i] + b[j] > x)
            j--;
        if(j >= 0 && a[i] + b[j] == x)
            cout << i << ' ' << j << endl;
    }

    return 0;
}

/*
作者：yxc
链接：https://www.acwing.com/activity/content/code/content/40069/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/