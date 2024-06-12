/*
二分图的最大匹配
AcWing 861. 二分图的最大匹配

https://www.acwing.com/solution/content/5334/

有点贪心的意味

导读：什么是最大匹配？
要了解匈牙利算法必须先理解下面的概念：

匹配：在图论中，一个「匹配」是一个边的集合，其中任意两条边都没有公共顶点。

最大匹配：一个图所有匹配中，所含匹配边数最多的匹配，称为这个图的最大匹配。

下面是一些补充概念：

完美匹配：如果一个图的某个匹配中，所有的顶点都是匹配点，那么它就是一个完美匹配。

交替路：从一个未匹配点出发，依次经过非匹配边、匹配边、非匹配边…形成的路径叫交替路。

增广路：从一个未匹配点出发，走交替路，如果途径另一个未匹配点（出发的点不算），
    则这条交替 路称为增广路（agumenting path）。

https://blog.csdn.net/sunny_hun/article/details/80627351
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 1e5 + 10;

int firstEdge[N], endPoint[M], nextEdge[M], idx;
int n1, n2, m;
int match[N];
bool st[N];  // 防止重复匹配一个点

void add(int u, int v) {
    endPoint[idx] = v;
    nextEdge[idx] = firstEdge[u];
    firstEdge[u] = idx;
    idx++;
}

bool find(int x) {
    /* 枚举所有对面的结点 */
    for(int edge = firstEdge[x]; edge != -1; edge = nextEdge[edge]) {
        int end = endPoint[edge];
        /* 如果对面的结点没有测试过 */
        if(not st[end]) {
            st[end] = true;
            /* if 对面的结点没有 matched,
            ** 或者说对面的match的男生还能 match 其他女生 */
            if(match[end] == 0 or find(match[end])) {
                match[end] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    memset(firstEdge, -1, sizeof(firstEdge));

    while(m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int res = 0;
    for(int i = 1; i <= n1; i++) {
        memset(st, false, sizeof(st));
        if(find(i)) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
/*
输入样例：
2 2 4
1 1
1 2
2 1
2 2
输出样例：
2
*/