/*
作者：random_srand
链接：https://www.acwing.com/solution/content/33974/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <iostream>
using namespace std;

const int N = 2e5 + 5;
typedef long long LL;

// 线段树的结点, 最大空间开4倍
struct Node {
    int l, r;
    int v;  // 最大值
} tr[N * 4];

int m, p;

// u为当前线段树的结点编号
void build(int u, int l, int r) {
    tr[u] = { l, r };
    if(l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

// 查询以u为根节点，区间[l, r]中的最大值
int query(int u, int l, int r) {
    //      Tl-----Tr
    //   L-------------R
    // 1.不必分治，直接返回
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].v;

    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    //     Tl----m----Tr
    //        L-------------R
    // 2.需要在tr的左区间[Tl, m]继续分治
    if(l <= mid) v = query(u << 1, l, r);

    //     Tl----m----Tr
    //   L---------R
    // 3.需要在tr的右区间(m, Tr]继续分治
    if(r > mid) v = max(v, query(u << 1 | 1, l, r));

    //     Tl----m----Tr
    //        L-----R
    // 2.3涵盖了这种情况
    return v;
}

// u为结点编号，更新该结点的区间最大值
void modify(int u, int x, int v) {
    if(tr[u].l == tr[u].r)
        tr[u].v = v;  // 叶节点，递归出口
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        // 分治处理左右子树, 寻找x所在的子树
        if(x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        // 回溯，拿子结点的信息更新父节点, 即pushup操作
        tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
    }
}

int main() {
    // n表示树中的结点个数, last保存上一次查询的结果
    int n = 0, last = 0;
    cin >> m >> p;

    // 初始化线段树, 结点的区间最多为[1, m]。
    build(1, 1, m);

    while(m--) {
        char op;
        cin >> op;
        if(op == 'A')  // 添加结点
        {
            int t;
            cin >> t;
            // 在n + 1处插入
            modify(1, n + 1, ((LL)t + last) % p);
            // 结点个数+1
            n++;
        } else {
            int L;
            cin >> L;
            // 查询[n - L + 1, n]内的最大值，u = 1，即从根节点开始查询
            last = query(1, n - L + 1, n);
            cout << last << endl;
        }
    }

    return 0;
}
