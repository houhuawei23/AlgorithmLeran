#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int g[N][N];  // 存储地图
int f[N][N];  // 存储距离
int n, m;
void bfs(int a, int b)  // 广度优先遍历
{
    queue<PII> q;
    q.push({a, b});
    // 初始点的距离为 0.
    // 可以不要这一句，因为f初始化的时候，各个点为0
    f[0][0] = 0;
    while (!q.empty()) {
        PII start = q.front();
        q.pop();
        // 这一句可以不要，因为入队的时候就置为了1
        g[start.first][start.second] = 1;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++)  // 往四个方向走
        {
            // 当前点能走到的点
            int x = start.first + dx[i], y = start.second + dy[i];
            // 如果还没有走过
            if (g[x][y] == 0) {
                // 走到这个点，并计算距离
                g[x][y] = 1;
                f[x][y] = f[start.first][start.second] + 1;
                // 从当前点走过去，则距离等于当前点的距离+1.
                // 这个点放入队列，用来走到和它相邻的点。
                q.push({x, y});
            }
        }
    }
    cout << f[n][m];
}

int main() {
    memset(g, 1, sizeof(g));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    bfs(1, 1);
}
