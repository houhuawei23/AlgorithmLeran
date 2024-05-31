/* Longest common subsequence
https://www.acwing.com/problem/content/899/
https://www.bilibili.com/video/BV14A411v7mP/?vd_source=5ecbb6b773d7fefbad376a941af576e2
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int MAXM = 1010;

char a[MAXN];
char b[MAXM];

int N, M;

int dp[MAXN][MAXM];

void print_str() {
    printf("strA: \n");
    printf("%s\n", a + 1);
    printf("strB: \n");
    printf("%s\n", b + 1);
}
void print_dp() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}
/*
dp[i][j]:
state:
    set: a[1:i], b[1:i] common subseqs
    attri: maxlength
calc: ?
    dp[i][j]: consider a[i], b[j]
    1. 00 不取 ai, bj: dp[i-1][j-1]
    2. 11 取 ai, bj, ai == bj: dp[i-1][j-1] + 1
    3. 01 不取 ai, 取 bj: num01 <= dp[i-1][j]
    4. 10 取 ai, 不取 bj: num10 <= dp[i][j-1]
    max(
        dp[i-1][j-1],
        num01,
        num10,
        dp[i-1][j-1] + 1 [if ai == bj]
    )

*/
int solveYxc() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    return dp[N][M];
}
/*
按两个序列末尾的字符是不是相等来区分
如果ai,bj相等，就可以直接转移到f[i-1][j-1]，
不相等的话，ai,bj一定有一个可以抛弃，可以对f[i-1][j],f[i][j-1]两种状态取max来转移
calc: dp[i][j]
    1. ai == bj: dp[i][j] = dp[i-1][j-1] + 1;
    2. ai != bj:
        - remove ai: dp[i-1][j]
        - remove bj: dp[i][j-1]

f[i][j]
表示在第一个序列的前i个字母中出现并且在第二个序列的前j个字母中出现的最大值
以第i个和第j个字母是否相同来划分
如果相同 f[i][j] = f[i - 1][j - 1] + 1
如果不相同 f[i][j] = max(f[i - 1][j], f[i][j - 1])
因为如果不相同，那么此时f[i][j]的值肯定不会大于f[i - 1][j]和f[i][j - 1]的最大值
那么一定会等于f[i - 1][j]和f[i][j - 1]的最大值
*/
int solveNew() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[N][M];
}

int main() {
    scanf("%d%d", &N, &M);
    scanf("%s%s", a + 1, b + 1);
    // print_str();
    // int res = solveYxc();
    int res = solveNew();
    // print_dp();
    printf("%d\n", res);
}

/*
输入样例：
4 5
acbd
abedc
输出样例：
3
*/

// void print_str() {
//     cout << "strA: " << endl;
//     for (int i = 1; i <= N; i++)
//         cout << strA[i];
//     cout << endl;
//     cout << "strB: " << endl;
//     for (int i = 1; i <= M; i++)
//         cout << strB[i];
//     cout << endl;
// }
// for (int i = 1; i <= N; i++)
//     strA[i] = getchar();
// for (int i = 1; i <= M; i++)
//     strB[i] = getchar();
// print_str();