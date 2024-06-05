/* 
291. 蒙德里安的梦想
状态压缩 DP
https://www.acwing.com/problem/content/description/293/
https://lishizheng.blog.csdn.net/article/details/112706309
1 <= N, M <= 11
输入样例：
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
输出样例：
1
0
1
2
3
5
144
51205

1、题目等价于按照列来横着放置小方块。（其他人写的行放置小方块）
2、f(i,j):摆放第i列，i-1列伸出来横着的方格状态为j的方案数，j为一个二进制数，
范围是0～行数位数的二进制范围；
3、i-1列转移到i列满足：(j & k) == 0,其中k是i-1列的状态；
4、同时每个有效的状态满足：j | k 不存在连续奇数个零，
即每个格子只能用纵向的格子来填；
*/

#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ull;
const int MAXN = 12, MAXM = 1 << MAXN;

/* N column, N row 1 -> 1 << N state */
ull f[MAXN][MAXM]; /* MAXM ?*/

bool st[MAXM]; /* is state valid? */

vector<int> validStates[MAXM];

int m, n;

int main() {
    while(cin >> n >> m, n || m) {
        auto init = [&]() {
            /*prepare all the valid state, not odd Zero */
            /* for all state from 00...0 to 11...1 */
            for(int i = 0; i <= (1 << n); i++) {
                int zeroCnt = 0;
                bool isValid = true;
                /* for each bit of i, right to left, low to high */
                for(int j = 0; j < n; j++) {
                    if((i >> j) & 1) {
                        /* i-th bit is 1, check zeroCnt, if odd, false */
                        if(zeroCnt & 1) {
                            isValid = false;
                            break;
                        }
                        zeroCnt = 0;
                    } else { /* is 0, zeroCnt++ */
                        zeroCnt++;
                    }
                }
                if(zeroCnt & 1) isValid = false;
                st[i] = isValid;
            }
            /* init f */
            memset(f, 0, sizeof(f));
            f[0][0] = 1;
        };

        auto solveSimple = [&]() {
            /* for each column */
            for(int i = 1; i <= m; i++) {
                /* for each posibale state */
                for(int j = 0; j < (1 << n); j++) {
                    /* for each posibile pre state */
                    for(int k = 0; k < (1 << n); k++) {
                        /* if not conflict and all valid */
                        if((k & j) == 0 and st[j | k]) {
                            f[i][j] += f[i - 1][k];
                        }
                    }
                }
            }
        };

        auto initValidStates = [&]() {
            /* init states vector that valid to state i */
            for(int i = 0; i < (1 << n); i++) {
                validStates[i].clear();
                for(int j = 0; j < (1 << n); j++) {
                    /* & 的优先级低，所以一定要加括号 （j&k） == 0 */
                    if((i & j) == 0 and st[i | j]) {
                        validStates[i].push_back(j);
                    }
                }
            }
        };

        auto solveOpt = [&]() {
            /* for each column */
            for(int i = 1; i <= m; i++) {
                /* for each posibale state */
                for(int j = 0; j < (1 << n); j++) {
                    /* for each posibile pre state */
                    for(auto k : validStates[j]) {
                        /* if not conflict and all valid */
                        f[i][j] += f[i - 1][k];
                    }
                }
            }
        };

        auto printValidStates = [&]() {
            cout << "printValidStates" << endl;
            for(int i = 0; i < (1 << n); i++) {
                cout << "cur state: " << i << endl;
                cout << "validStates: ";
                for(auto k : validStates[i]) {
                    cout << k << " ";
                }
                cout << endl;
            }
        };
        auto printF = [&]() {
            cout << "print f: " << endl;
            for(int i = 0; i <= m; i++) {
                for(int j = 0; j < (1 << n); j++) {
                    cout << f[i][j] << " ";
                }
                cout << endl;
            }
        };

        init();
        // printF();
        // solveSimple();

        // printValidStates();
        initValidStates();
        // printValidStates();
        // printF();

        solveOpt();
        // printF();

        cout << f[m][0] << endl;
    }
}

/*
1 2
0 0
*/