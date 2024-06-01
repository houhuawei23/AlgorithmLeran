/*
作者：关注永雏塔菲谢谢喵
链接：https://www.acwing.com/solution/content/219676/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
#define ls(u) tr[u].son[0]
#define rs(u) tr[u].son[1]
const int N = 1e5 + 505, L = 350, INF = 0x3f3f3f3f, mod = 998244353;
const double alpha = 0.725, eps = 1e-8;
typedef long long LL;
char *p1, *p2, buf[100000];
#define nc()                                                                \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) \
         ? EOF                                                              \
         : *p1++)
inline int read() {
    int x = 0, f = 1;
    char ch = nc();
    while (ch < 48 || ch > 57) {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    if (ch == '-')
        f = -1;
    while (ch >= 48 && ch <= 57)
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = nc();
    return f * x;
}
inline void write(int x) {
    if (x < 10)
        putchar(x ^ 48);
    else
        write(x / 10), write(x % 10);
}
int pt;
inline void read(char* opt) {
    char ch = nc();
    while (ch < 65 || ch > 132 || ch > 90 && ch < 97)
        ch = nc();
    while (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 132 || ch == '-')
        opt[pt++] = ch, ch = nc();
    opt[pt] = 0, pt = 0;
}
struct matrix {
    int M[2][2];
    matrix(int a = 1, int b = 0, int c = 0, int d = 1) {
        M[0][0] = a, M[0][1] = b, M[1][0] = c, M[1][1] = d;
    }
    inline matrix operator*(const matrix& t) const {
        matrix c(0, 0, 0, 0);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++)
                    c.M[i][j] = (c.M[i][j] + 1ll * M[i][k] * t.M[k][j]) % mod;
            }
        }
        return c;
    }
    inline void init() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                M[i][j] = read();
        }
    }
    inline void print() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                write(M[i][j]), putchar(' ');
        }
        putchar('\n');
    }
} I, lm[N], rm[N];
int len, bk[N], st[L], ed[L], res[L];
int n, m, q[N];
matrix pre_lm[L][L], pre_rm[L][L];
int sz[L];
inline void rebuild(int t) {
    sz[t] = 0, res[t] = 0;
    for (int i = st[t]; i <= ed[t]; i++) {
        if (q[i] == 1 || q[i] == 2) {
            sz[t]++;
            pre_lm[t][sz[t]] = lm[i] * pre_lm[t][sz[t] - 1],
            pre_rm[t][sz[t]] = pre_rm[t][sz[t] - 1] * rm[i];
        } else {
            if (!sz[t])
                res[t]++;
            else
                sz[t]--;
        }
    }
    //   for(int i=0;i<=sz[t];i++)pre_lm[t][i].print(),pre_rm[t][i].print();
}
int stk[N];
inline void query(int l, int r, matrix& ls, matrix& rs, int& res, int last) {
    int top = 0;
    for (int i = l; i <= r; i++) {
        if (q[i] == 1 || q[i] == 2)
            stk[top++] = i;
        else if (top)
            top--;
        else
            res++;
    }
    for (int i = 0; i < top - last; i++)
        ls = lm[stk[i]] * ls, rs = rs * rm[stk[i]];
}
inline matrix query(int l, int r) {
    if (bk[l] == bk[r]) {
        matrix ls, rs;
        int cnt = 0;
        query(l, r, ls, rs, cnt, 0);
        return ls * rs;
    } else {
        matrix ls1, rs1, ls2, rs2, ans1, ans2;
        int last = 0;
        query(st[bk[r]], r, ls2, rs2, last, 0);
        for (int i = bk[r] - 1; i >= bk[l] + 1; i--) {
            if (sz[i] - last > 0)
                ans1 = ans1 * pre_lm[i][sz[i] - last],
                ans2 = pre_rm[i][sz[i] - last] * ans2, last = 0;
            else
                last -= sz[i];
            last += res[i];
        }
        query(l, ed[bk[l]], ls1, rs1, last, last);
        return ls2 * ans1 * ls1 * rs1 * ans2 * rs2;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    n = read(), m = read();
    len = sqrt(n) + 1;
    for (int i = 1; i <= n; i++) {
        bk[i] = (i - 1) / len, ed[bk[i]] = i;
        if (!st[bk[i]])
            st[bk[i]] = i, pre_lm[bk[i]][0] = I, pre_rm[bk[i]][0] = I;
    }
    for (int i = 1; i <= n; i++) {
        int opt = read();
        q[i] = opt;
        if (opt == 1)
            lm[i].init(), rm[i] = I;
        else if (opt == 2)
            lm[i] = I, rm[i].init();
    }
    for (int i = bk[1]; i <= bk[n]; i++)
        rebuild(i);
    for (int i = 0; i < m; i++) {
        int opt = read(), pos;
        if (opt == 1) {
            pos = read(), q[pos] = read();
            if (q[pos] == 1)
                lm[pos].init(), rm[pos] = I;
            else if (q[pos] == 2)
                lm[pos] = I, rm[pos].init();
            rebuild(bk[pos]);
        } else {
            int l = read(), r = read();
            matrix ans = query(l, r);
            ans.print();
        }
    }
}
