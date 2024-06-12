/*
AcWing
860. 染色法判定二分图
1e5

输入样例：
4 4
1 3
1 4
2 3
2 4
输出样例：
Yes

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/48778/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

https://www.acwing.com/solution/content/105874/

什么叫二分图

有两顶点集且图中每条边的的两个顶点分别位于两个顶点集中，每个顶点集中没有边直接相连接！

说人话的定义：
图中点通过移动能分成左右两部分，左侧的点只和右侧的点相连，右侧的点只和左侧的点相连。
*/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];  // 标记每个点的颜色(0表示未染色),color[i]=0,1,...

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c) {
    color[u] = c;  // 点u染c色

    // 遍历u的所有邻接点j
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];

        // j未染色
        if (!color[j]) {
            // 从j开始深度优先遍历图,逐个染色
            if (!dfs(j, 3 - c))
                return false;
        }
        // j已染色
        else if (color[j] == c)
            return false;  // 出现奇数环导致j与i同色
    }

    return true;
}

int main() {
    scanf("%d%d", &n, &m);

    // 建立邻接表
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    // 染色法
    bool flag = true;
    // 考虑到非连通图的情况,保证遍历到每一个点
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {       // 若i未染色
            if (!dfs(i, 1)) {  // 从i开始深度优先遍历图,逐个染色
                flag = false;  // 出现矛盾,染色失败
                break;
            }
        }
    }

    if (flag)
        puts("Yes");
    else
        puts("No");

    return 0;
}
