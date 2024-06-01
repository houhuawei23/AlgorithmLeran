#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;

int a[MAXN];
int n;

int main() {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] + a[j] == 0)
                res++;
        }
    }
    cout << res << endl;
}
/*

输入样例：
5
1 2 3 -1 -2
输出样例：
2
*/