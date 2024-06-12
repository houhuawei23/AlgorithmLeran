#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
// n1表示左边点的数量(男生)，n2表示右边点的数量(女生)，图中有m条边
int h[N], e[M], ne[M], idx;
// h[]邻接表的头节点，e[]存值，ne[]存下一个点的地址，idx存当前点
int match[N];  // 表示右边点其对应的点，即女与男配对里的男生
bool st[N];    // 防止重复匹配一个点

void add(int a, int b) {
    // 用邻接表存图
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
// 匈牙利算法的实现
bool find(int x) {
    // 枚举这个男生考虑的妹子，即其邻边连接的点
    for(int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];  // 表示当前妹子的点编号
        if(!st[j]) {
            // 还没有匹配过
            st[j] = true;
            if(match[j] == 0 || find(match[j])) {
                // 当前妹子没有匹配到男生||与其匹配的男生有其他备胎
                match[j] = x;  // 枚举的男生与当前妹子匹配成功
                return true;
            }
        }
    }
    return false;  // 都匹配不成功，单身狗一个
}

int main() {
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);

    while(m--)  // 添加边
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int res = 0;                  // res表示当前匹配成功的数量
    for(int i = 1; i <= n1; i++)  // 遍历所有男生n1
    {
        memset(st, false, sizeof st);  // 清空要考虑的女生
        if(find(i))
            res++;
        // 如果男生成功匹配到一个妹子，匹配数+1
    }

    cout << res << endl;

    return 0;
}
