/*

作者：关注永雏塔菲谢谢喵
链接：https://www.acwing.com/solution/content/219676/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
/*

题目大意是要维护n条指令：
①左乘一个矩阵
②右乘一个矩阵
③删除最后乘入的矩阵

为了便于操作，每条指令可以等价成如下三种指令：
①左乘一个矩阵，右乘一个单位阵
②右乘一个矩阵，左乘一个单位阵
③左右两边同时删去一个矩阵

然后进行m次操作：
①将指定位置的指令修改成新输入的指令
②询问从l~r位置的指令执行后的结果

如果暴力模拟的话可以获得35分，如果不考虑指令3，简单的维护一颗线段树即可，可以获得20分。
考虑指令3感觉就比较难操作了，呃呃我也没想到要用线段树维护什么信息。
于是采用分块的方法暴力做，分块的话根据题意要快速修改每一块里的指令，以及每一块里矩阵的乘积，
同时删除操作还要考虑当前块里的矩阵不够删要从前面的块删的情况，所以还要同时记录当前块“还欠”多少矩阵没删。
这里考虑用splay来维护每一个块的矩阵，要注意矩阵乘法的顺序。

①对于修改操作：每次暴力修改块，即修改指令后重新对该块建树，
同时查询时只要计算一下k=当前块矩阵个数-后面的块欠的矩阵个数，
然后求splay前k个矩阵的乘积即可，这一部分每次操作都是O(n^(1/2)log(n))的复杂度。

②对于每次查询操作：先特判一下查询的左端点和右端点在不在同一块里，若在直接暴力计算即可，复杂度是O(n^(1/2))的。
若不在，就暴力计算左右端点所在块的指令结果，同时从右往左扫描中间的块（因为要考虑后面的块欠下的矩阵），
用res来存储后面的块总共欠的矩阵，对于完整的块直接求splay前k个矩阵的乘积即可。
综上一次查询的时间复杂度是O（n^(1/2)log(n)）的。

综上，总的时间复杂度是 O(n^(3/2)log(n)) 的，简单计算一下大概要计算五亿多次，
但是由于每个splay的大小其实很小，实际上只用算两亿次左右，时间限制是1.5s，
可见时间很紧了，所以还要再加点优化减小常数，详见代码注释。

作者：关注永雏塔菲谢谢喵
链接：https://www.acwing.com/solution/content/219676/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
char *p1, *p2, buf[100000];
#define nc()                                                                \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) \
         ? EOF                                                              \
         : *p1++)
inline int Read() {
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
}  // 快读函数可以优化几百毫秒
const int N = 1e5 + 10, M = 1010;
const int mod = 998244353;
struct matrix {
    int M[2][2];
    inline matrix(int a = 1, int b = 0, int c = 0, int d = 1) {
        M[0][0] = a, M[0][1] = b, M[1][0] = c, M[1][1] = d;
    }
    inline matrix operator*(const matrix& B) {
        matrix C(0, 0, 0, 0);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++)
                    C.M[i][j] = (C.M[i][j] + (LL)M[i][k] * B.M[k][j]) % mod;
            }
        }
        return C;
    }
};  // 矩阵类
int len = sqrt(N) + 1;  // 块的大小
matrix I;               // 单位阵
void show(const matrix& A) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << A.M[i][j] % mod << ' ';
    }
    cout << '\n';
}
inline matrix read() {
    matrix C;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            C.M[i][j] = Read();
    }
    return C;
}  // 矩阵的读入函数
struct node {
    int son[2], p, size;
    matrix ls, rs;
} tr[N];  // splay
int cnt[M], cmd[N], bk[N], st[M], ed[M];
// cnt记录当前块还欠多少矩阵要在前面的块删除
// cmd[i]是第i条指令的值
// bk[i]记录i所在的块号
// st[i]是第i块的起始位置
// ed[i]是第i块的结束位置
matrix lm[N], rm[N];
// lm[i]表示第i条指令左乘的矩阵
// rm[i]表示第i条指令右乘的矩阵
// 若第i条指令是3，则无效
int n, m, root[M], used[N];
// used[i]为真则表示第i条指令还在splay上没有被删除
// root[i]是第i块的splay的根节点
inline void pushup(int u) {
    int l = tr[u].son[0], r = tr[u].son[1];
    tr[u].ls = tr[r].ls * lm[u] * tr[l].ls;
    tr[u].rs = tr[l].rs * rm[u] * tr[r].rs;
    tr[u].size = tr[l].size + tr[r].size + 1;
}  // 注意顺序
inline void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = (tr[y].son[1] == x);
    tr[z].son[tr[z].son[1] == y] = x, tr[x].p = z;
    tr[y].son[k] = tr[x].son[k ^ 1], tr[tr[x].son[k ^ 1]].p = y;
    tr[y].p = x, tr[x].son[k ^ 1] = y;
    pushup(y), pushup(x);
}
inline void splay(int& root, int x, int k) {
    while (tr[x].p != k) {
        int y = tr[x].p, z = tr[y].p;
        if (z != k) {
            if ((tr[z].son[1] == y) ^ (tr[y].son[1] == x))
                rotate(x);
            else
                rotate(y);
        }
        rotate(x);
    }
    if (!k)
        root = x;
}
inline void insert(int& root, int x) {
    int u = root, p = 0;
    while (u) {
        if (x < u)
            p = u, u = tr[u].son[0];
        else
            p = u, u = tr[u].son[1];
    }
    if (!p)
        root = x;
    else
        tr[p].son[p < x] = x;
    tr[x].p = p;
    splay(root, x, 0);
    used[x] = 1;
}
// ↑为splay的一些函数
inline void del(int& root) {
    int u = root, p = 0;
    while (u)
        p = u, u = tr[u].son[1];
    splay(root, p, 0);
    used[p] = 0;
    int l = tr[p].son[0];
    root = l, tr[l].p = 0, tr[p].son[0] = 0;
    pushup(p);
}  // 删除splay最后面的点，对应指令3
inline int get_idx(int u, int k) {
    if (k <= tr[tr[u].son[0]].size)
        return get_idx(tr[u].son[0], k);
    else if (k <= tr[tr[u].son[0]].size + 1)
        return u;
    else
        return get_idx(tr[u].son[1], k - 1 - tr[tr[u].son[0]].size);
}  // 返回splay的第k个节点
inline void build(int blocks) {
    int l = st[blocks], r = ed[blocks];
    root[blocks] = 0, cnt[blocks] = 0;
    for (int i = l; i <= r; i++)
        tr[i].p = tr[i].son[0] = tr[i].son[1] = 0, tr[i].size = 1,
        tr[i].ls = lm[i], tr[i].rs = rm[i];
    for (int i = l; i <= r; i++) {
        if (cmd[i] == 3) {
            if (!root[blocks])
                cnt[blocks]++;
            else
                del(root[blocks]);
        } else
            insert(root[blocks], i);
    }
}  // 扫描第blocks块，暴力建树
int stk[M], top;
inline matrix query(int l, int r) {
    int res = 0;  // 记录当前还欠多少矩阵要删除
    matrix ans = I;
    if (bk[l] == bk[r]) {
        top = 0;
        for (int i = l; i <= r; i++) {
            if (cmd[i] == 3 && top)
                top--;
            else if (cmd[i] != 3)
                stk[top++] = i;
        }
        for (int i = 0; i < top; i++)
            ans = lm[stk[i]] * ans * rm[stk[i]];
        return ans;
        // l和r同块就暴力计算
    } else {
        matrix ls = I, rs = I;  // 所有左乘矩阵乘积，右乘矩阵乘积
        top = 0;
        for (int i = st[bk[r]]; i <= r; i++) {
            if (cmd[i] == 3) {
                if (top)
                    top--;
                else
                    res++;
            } else
                stk[top++] = i;
        }
        for (int i = 0; i < top; i++)
            ls = lm[stk[i]] * ls, rs = rs * rm[stk[i]];
        // 暴力计算r所在块的矩阵乘积
        for (int b = bk[r] - 1; b >= bk[l] + 1; b--) {
            if (res < tr[root[b]].size) {
                int ptr = get_idx(root[b], tr[root[b]].size - res);
                splay(root[b], ptr, 0);
                int lp = tr[ptr].son[0];
                ls = ls * lm[ptr] * tr[lp].ls,
                rs = tr[lp].rs * rm[ptr] * rs;  // 注意顺序
                res = 0;
                // 如果够删就清空res
            } else
                res -=
                    tr[root[b]]
                        .size;  // 不够删就能删多少删多少，只是查询不用真的删除
            res += cnt[b];  // 加上当前块原本就欠的矩阵
        }

        top = 0;
        for (int i = l; i <= ed[bk[l]]; i++) {
            if (cmd[i] == 3 && top)
                top--;
            else if (cmd[i] != 3)
                stk[top++] = i;
        }
        for (int i = top - res - 1; i >= 0; i--)
            ls = ls * lm[stk[i]], rs = rm[stk[i]] * rs;
        // 暴力计算l所在块的矩阵乘积
        return ls * rs;
    }
}
void solve() {
    n = Read(), m = Read();
    int last = -1;
    for (int i = 1; i <= n; i++) {
        bk[i] = (i - 1) / len;
        if (last != bk[i])
            st[bk[i]] = i;
        ed[bk[i]] = i, last = bk[i];  // 处理每个块的起始位置和结束位置
        cmd[i] = Read();
        if (cmd[i] == 1)
            lm[i] = read(), rm[i] = I;
        else if (cmd[i] == 2)
            rm[i] = read(), lm[i] = I;
    }
    for (int i = 1; i <= n; i++) {
        build(bk[i]);
        i = ed[bk[i]];
    }  // 暴力建树
    int op, pos, v, l, r;
    for (int i = 1; i <= m; i++) {
        op = Read();
        if (op == 1) {
            pos = Read(), v = Read();
            last = cmd[pos], cmd[pos] = v;
            if (last == 3 && v == 3)
                continue;
            else if (v == 3)
                build(bk[pos]);
            else if (last == 3) {
                if (v == 1)
                    lm[pos] = read(), rm[pos] = I;
                else if (v == 2)
                    rm[pos] = read(), lm[pos] = I;
                build(bk[pos]);
            } else {
                if (used[pos])
                    splay(root[bk[pos]], pos, 0);
                if (v == 1)
                    lm[pos] = read(), rm[pos] = I;
                else if (v == 2)
                    rm[pos] = read(), lm[pos] = I;
                if (used[pos])
                    pushup(pos);
            }
            // 小优化，可以优化几百毫秒，很关键
            // 如果修改的指令原本是3，改完还是3，那就不用管
            // 如果新指令是3，或者原本这条指令是3，那就暴力建树
            // 如果原本指令和新指令都不是3,那就判断一下这个矩阵有没有被删
            // 如果被删了直接修改lm,rm即可，否则还要修改一下splay，但是最坏是O(log(n))，怎么样都比暴力建
            // 树快不少
        } else if (op == 2) {
            l = Read(), r = Read();
            show(query(l, r));
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
