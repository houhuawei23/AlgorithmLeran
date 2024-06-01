/*
最优性剪枝 TLE80分
*/
#include <bits/stdc++.h>

#pragma GCC optimize(2)
using namespace std;

const int N = 2010;
using ll = long long;

char buf[1 << 20], *p1, *p2;
#define getchar()                                                            \
    (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) \
         ? 0                                                                 \
         : *p1++)
inline void read(int& x) {
    x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return;
}
inline void write(ll x) {
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

typedef struct node {
    int num;   // 自己的编号
    int w;     // 自己的权值
    ll w_all;  // 自己加上子树的权值。

    node* fa;              // 指向自己的父亲
    vector<node*> childs;  // 指向自己的孩子

} node;

node v[N];  // 存放节点
ll wA[N];

void travel(node* now) {
    // 计算子树权重值
    now->w_all = now->w;
    for (node* c : now->childs) {
        travel(c);
        now->w_all += c->w_all;  // 计算一遍权重
    }
    wA[now->num] = now->w_all;
}

int main() {
    v[1].fa = NULL;
    int n, m;
    read(n);
    read(m);
    for (int i = 1; i <= n; i++) {
        v[i].num = i;
        read(v[i].w);
    }
    for (int i = 2; i <= n; i++) {
        int f;
        read(f);
        v[i].fa = &v[f];               // 指向父亲
        v[f].childs.push_back(&v[i]);  // 指向儿子
    }

    node* root = &v[1];  // 根节点
    travel(root);
    while (m--) {
        int x;
        read(x);
        node* now = root;  // 一开始树是完整的
        for (auto& node : v)
            node.w_all = wA[node.num];
        // 出口在哪？
        while (1) {
            // 需要找到这树上最小的点
            node *ans = now, *p = now;
            ll A = abs(now->w_all - 2 * ans->w_all);
            while (p != NULL) {
                // 计算一下
                node* next = NULL;
                for (node* c : p->childs) {
                    if (c->w_all) {
                        ll B = abs(now->w_all - 2 * c->w_all);
                        if (A > B || (A == B && c->num < ans->num)) {
                            ans = c;
                            A = B;
                        }
                        if (now->w_all >= 2 * c->w_all)
                            continue;
                        next = c;
                    }
                }
                p = next;
            }
            if (ans == now)
                break;  // 树上没有东西了
            // 输出一下
            write(ans->num);
            putchar(' ');
            // 判断是否在树上
            p = &v[x];
            bool flag = 0;
            while (p != now->fa) {
                if (p == ans) {
                    flag = 1;
                    now = ans;
                    break;
                }  // 在树上
                p = p->fa;
            }

            if (!flag) {
                // 删除
                node* p2 = ans->fa;
                while (p2 != now->fa) {
                    p2->w_all -= ans->w_all;
                    p2 = p2->fa;
                }
                ans->w_all = 0;
            }
        }
        putchar('\n');
    }
}
