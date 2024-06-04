/*
Edit Distance.
https://www.acwing.com/problem/content/901/
Linear DP.

O(N*M*L^2) = 1e8

输入样例：
3 2
abc
acd
bcd
ab 1
acbd 2
输出样例：
1
3
*/

#include <bits/stdc++.h>
using namespace std;

bool debug = false;

const int MAXN = 1010;
const int MAXLEN = 15;
int n, m;

char strings[MAXN][MAXLEN];
char querys[MAXN][MAXLEN];
int limits[MAXN];
int f[MAXLEN][MAXLEN];

int edit_distance(const char a[], const char b[]) {
    /* a -> b */
    int lena = strlen(a + 1), lenb = strlen(b + 1);
    for (int i = 1; i <= lena; i++) {
        /* f[i][0] */
        f[i][0] = i;
    }
    for (int j = 1; j <= lenb; j++) {
        f[0][j] = j;
    }
    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1];
            else {
                f[i][j] =
                    min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
            }
        }
    }
    if (debug) {
        printf("eidit_distance of (a, b) is %d\n", f[lena][lenb]);
        printf("a: %s\n", a + 1);
        printf("b: %s\n", b + 1);
    }
    return f[lena][lenb];
}

int queryCalc(const int qidx, const int limit) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (edit_distance(strings[i], querys[qidx]) <= limit) {
            cnt++;
        }
    }
    if (debug) {
        printf("query of b, satisfied num: %d\n", cnt);
        printf("b: %s\n", querys[qidx] + 1);
    }
    return cnt;
}

int main() {
    // cin >> n >> m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", strings[i] + 1);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%s%d", querys[i] + 1, &limits[i]);
    }
    // edit_distance(" abcd", " abcd");
    // edit_distance(strings[1], querys[1]);
    // edit_distance(strings[2], querys[1]);
    // edit_distance(strings[1], querys[2]);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", queryCalc(i, limits[i]));
        // cout <<  << endl;
    }
}