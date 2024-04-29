#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int path[N];
bool state[N];  // state[i] = true iif cur path used number i

int n;

void dfs(int len) {
    // cout << "len: " << len << endl;
    if (len >= n) {
        for (int i = 1; i <= n; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int e = 1; e <= n; e++) {
        if (state[e])
            continue;
        path[len + 1] = e;
        state[e] = true;
        dfs(len + 1);
        state[e] = false;
    }
}

int main() {
    cin >> n;
    // cout << n;
    dfs(0);
}