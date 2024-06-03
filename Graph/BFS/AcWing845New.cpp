/*
问题:
1. bfs 要防止重复搜索, 要用visited记录
2. 准确理解题意, "上下左右" 搞明白走法和判断条件, 手动推算, 测试检查, 务必准确
3. 状态表示, 简单方便, 灵活
*/

#include <bits/stdc++.h>

using namespace std;

string targetStr = "12345678x";

struct Node {
    int idx;
    int cnt;
    string str;

    void print() {
        cout << "cnt: " << cnt << ", idx: " << idx << endl;
        // cout << "str: " << str << endl;
        cout << "grid: " << endl;
        for (auto i = 0; i < 9; i++) {
            cout << str[i];
            if ((i + 1) % 3 == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }
    bool check() {
        if (str == targetStr) {
            return true;
        }
        return false;
    }
    void mswap(int tidx) {
        swap(str[idx], str[tidx]);
        idx = tidx;
    }
};

unordered_set<string> visited;

queue<Node> q;

void printQueue(queue<Node> q) {
    cout << "- Queue size: " << q.size() << endl;
    while (!q.empty()) {
        q.front().print();
        q.pop();
    }
    cout << "- Queue end" << endl;
}

int dds[4] = {-3, 1, 3, -1};

int main() {
    Node start;
    char ch;

    for (int i = 0; i < 9; i++) {
        cin >> ch;
        start.str += ch;
        if (ch == 'x')
            start.idx = i;
    }
    start.cnt = 0;

    Node tmp = start;
    tmp.mswap(2);

    visited.insert(start.str);
    q.push(start);

    while (!q.empty()) {
        Node curr = q.front();
        if (curr.check()) {
            cout << curr.cnt << endl;
            return 0;
        }
        q.pop();
        for (auto dd : dds) {
            // cout << "dd" << dd << endl;
            int nidx = curr.idx + dd;

            {
                if (!(nidx >= 0 && nidx <= 8)) {
                    continue;
                }
                /* same row or col */
                if (!(nidx / 3 == curr.idx / 3 || nidx % 3 == curr.idx % 3)) {
                    continue;
                }
            }
            Node next = curr;
            next.mswap(nidx);
            next.cnt++;
            if (visited.count(next.str) != 0) {
                /* find, jump */
                continue;
            }

            visited.insert(next.str);
            q.push(next);
        }
    }
    cout << -1;
}