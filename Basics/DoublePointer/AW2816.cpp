#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) scanf("%d", &b[i]);

    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] == b[j]) i++;
        j++;
    }

    if(i == n)
        puts("Yes");
    else
        puts("No");

    return 0;
}
/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/589289/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/