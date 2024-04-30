#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;

int mase[MAX][MAX];

int n, m;

// int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Node {
    int depth;
    int x, y;
    int pidx;
    // vector<int> path;
};

queue<Node> q;

// void bfs()
void pnode(Node node) {
    cout << "==node==" << endl;
    cout << "depth: " << node.depth << endl;
    cout << "(" << node.x << ", " << node.y << ")" << endl;
    cout << "pidx: " << node.pidx << endl;
}
void pmase() {
    cout << "mase: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mase[i][j] << " ";
        }
        cout << endl;
    }
    cout << "mase end" << endl;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mase[i][j];
        }
    }
    // pmase();
    // Node start = {0, 0, 0, -1};
    Node start = {.depth = 0, .x = 1, .y = 1, .pidx = -1};
    // pnode(start);

    q.push(start);

    while (!q.empty()) {
        Node node = q.front();
        // pnode(node);
        q.pop();
        if (node.x == n && node.y == m) {
            cout << node.depth << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            /*
            if ((i + 2) % 4 == node.pidx) {
                continue;
            }
            */

            int nx = node.x + dx[i];
            int ny = node.y + dy[i];

            if (!(nx >= 1 && nx <= n)) {
                continue;
            }
            if (!(ny >= 1 && ny <= m)) {
                continue;
            }
            if (mase[nx][ny] == 0) {
                /* can go */
                mase[nx][ny] = 1;
                Node nd = {node.depth + 1, nx, ny, i};
                q.push(nd);
            }
        }
    }
}