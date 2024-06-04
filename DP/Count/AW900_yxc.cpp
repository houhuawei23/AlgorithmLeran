/*

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/62496/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N];

void solve() {
    cin >> n;

    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % mod;

    cout << f[n] << endl;
}

int dp[N][N];
void print_dp() {
    cout << "dp: " << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
void solve2() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        // dp[0][i] = 1;
    }
    // print_dp();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] % mod;
            if (j >= i)
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % mod;
        }
    // print_dp();
    cout << dp[n][n] << endl;
}
int main() {
    solve2();
    return 0;
}
