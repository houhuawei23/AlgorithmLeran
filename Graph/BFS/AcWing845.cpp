/* not finished */

#include <bits/stdc++.h>

using namespace std;

const int N = 5;
struct Node {
    int idx;
    int cnt;
    int dd;
    vector<int> v;
};

// vector<int> init;
queue<Node> q;
/*
int grid[N][N];
for (int i = 1; i < = 3; i++) {
    for (int j = 1; j <= 3; j++) {
        cin >> grid[i][j];
    }
}
*/
char ch;

int dd[4] = {-3, 1, 3, -1};

void printNode(Node node) {
    cout << endl;
    for (int i = 0; i < node.cnt; i++) {
        cout << "--";
    }
    cout << "cnt: " << node.cnt << ", idx: " << node.idx << endl;
    for (int i = 0; i < node.cnt; i++) {
        cout << "--";
    }
    for (auto e : node.v) {
        cout << e << " ";
    }
    cout << endl;
}

bool check(vector<int> v) {
    for (int i = 1; i <= 7; i++) {
        if (v[i - 1] != i) {
            return false;
        }
    }
    if (v[8] != 0) {
        return false;
    }
    return true;
}
/*
1 2 x 4 6 3 7 5 8
*/
int main() {
    Node init;

    for (int i = 0; i < 9; i++) {
        cin >> ch;
        if (ch >= '1' && ch <= '8') {
            init.v.push_back(ch - '0');
        } else if (ch == 'x') {
            init.v.push_back(0);
            init.idx = i;
        } else {
            assert(false);
        }
    }
    init.cnt = 0;
    init.dd = -1;
    // printNode(init);
    // exit();
    q.push(init);

    while (!q.empty()) {
        Node n = q.front();
        q.pop();
        // if (check(n.v)) {
        //     cout << "check success!" << endl;
        //     printNode(n);
        //     cout << n.cnt << endl;
        //     return 0;
        // }
        for (int i = 0; i <= 3; i++) {
            if ((i + 2) % 4 == n.dd) {
                // cout << "dd" << endl;
                continue;
            }
            int nidx = n.idx + dd[i];
            if (!(nidx >= 0 && nidx <= 8)) {
                continue;
            }
            Node nd = n;
            nd.idx = nidx;
            swap(nd.v[n.idx], nd.v[nidx]);
            nd.cnt = n.cnt + 1;
            nd.dd = i;
            if (check(nd.v)) {
                // cout << "check success!" << endl;
                // printNode(nd);
                cout << nd.cnt << endl;
                return 0;
            }
            // printNode(nd);
            q.push(nd);
        }
    }
}