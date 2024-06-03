/*
Shortest Edit Distance.
https://www.acwing.com/problem/content/904/
Linear DP.

输入样例：
10
AGTCTGACGC
11
AGTAAGTAGGC
输出样例：
4

voideo: 
【E07 线性DP 编辑距离】 https://www.bilibili.com/video/BV1gk4y1177j/
solution:
https://www.acwing.com/solution/content/5607/
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

void print_dp() {
    cout << "dp: " << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}
/*
f[i][j]: a[1~i] -> b[1~j] minimal operation number
由于对字符串的操作顺序可以交换的,
所以不妨假定我们转换的操作序列的最后一步都是对a的最后一个字符进行的操作
则考察 a[i] 与 b[j]
- if a[i] == b[j], then only need to convert a[1~(i-1)] to b[1~(j-1)]
    - opnum = f[i-1][j-1]
- else:
    - if last operation is delete a[i]:
        - firstly we need convert a[1~(i-1)] to b[1~j], then delete a[i], so:
        - opnum = f[i-1][j] + 1
    - if last operation is replace a[i] with b[j]:
        - firstly we need convert a[1~(i-1)] to b[1~(j-1)], then replace a[i]:
        - opnum = f[i-1][j-1] + 1
    - if last operation is insert b[j] to the end of a (insert after a[i]):
        - need to convert a[1~i] to b[1~(j-1)], then insert:
        - opnum = f[i][j-1] + 1

then:
if a[i] == b[j]:
    f[i][j] = f[i-1][j-1]
else:
    f[i][j] = min{f[i-1][j] + 1, f[i-1][j-1] + 1, f[i][j-1] + 1}
            = min{f[i-1][j], f[i-1][j-1], f[i][j-1]} + 1
init dp:
dp[0][0] = 0
dp[i][0] = i, a[1~i] to "", need i delete
dp[0][j] = j, "" to b[1~j], need j insert

traverse order:
for i in [1..n]
    for j in [1..n]
*/
int main() {
    scanf("%d%s", &n, a + 1);
    scanf("%d%s", &m, b + 1);

    for (int i = 1; i <= n; i++)
        f[i][0] = i;
    for (int i = 1; i <= m; i++)
        f[0][i] = i;
    // print_dp();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] =
                    min(min(f[i - 1][j], f[i - 1][j - 1]), f[i][j - 1]) + 1;
            }
        }
    }
    // print_dp();

    // printf("%s\n", a + 1);
    // printf("%s\n", b + 1);

    printf("%d\n", f[n][m]);

    return 0;
}
