#include <bits/stdc++.h>

using namespace std;

const int N = 10;

/* 0 for '.' , 1 for 'Q' */
int board[N][N];

int n;

bool check(int row, int col) {
    /* same col */
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }
    /* left upper */
    for (int i = 1; row - i >= 0 && col - i >= 0; i++) {
        if (board[row - i][col - i]) {
            return false;
        }
    }
    /* right upper */
    for (int i = 1; row - i >= 0 && col + i < n; i++) {
        if (board[row - i][col + i]) {
            return false;
        }
    }
    return true;
}

void dfs(int row) {
    if (row >= n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j] ? 'Q' : '.';
                cout << ch;
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (check(row, j)) {
            board[row][j] = 1;
            dfs(row + 1);
            board[row][j] = 0;
        }
    }
}
int main() {
    cin >> n;
    dfs(0);
}