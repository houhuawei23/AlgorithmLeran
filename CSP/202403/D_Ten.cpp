/*
Need faster Algorithm, 
force only 40/100, time and memory limit exceed.
*/

#include <bits/stdc++.h>

using namespace std;

bool Debug = false;

const int CMAX = 1e9 + 5;
const int MMAX = 3e5 + 5;

uint16_t grids[CMAX];

uint32_t ops[MMAX];
uint32_t numWater[MMAX];

int c, m, n;

void print_grids() {
    cout << "grids: ";
    for (int i = 1; i <= m; i++) {
        if (grids[i] == 0) {
            cout << 0 << " ";
        } else {
            cout << grids[i] << " ";
        }
    }
    cout << endl;
}

void print_ops() {
    cout << "ops: ";
    for (int i = 1; i <= n; i++) {
        cout << ops[i] << " ";
    }
    cout << endl;
}

int numWaterGrid() {
    int num = 0;
    for (int i = 1; i <= m; i++) {
        if (grids[i] != 0)
            num++;
    }
    return num;
}

void sim(uint32_t p) {
    if (Debug) {
        cout << "sim on: " << p << endl;
    }

    grids[p] += 1;
    while (true) {
        if (Debug) {
            print_grids();
        }
        bool changed = false;
        for (int i = 1; i <= c; i++) {
            if (grids[i] < 5)
                continue;
            // else: >= 5
            changed = true;
            grids[i] = 0;

            for (int l = i - 1; l >= 1; l--) {
                if (grids[l] != 0) {
                    grids[l] += 1;
                    break;
                }
            }

            for (int r = i + 1; r <= c; r++) {
                if (grids[r] != 0) {
                    grids[r] += 1;
                    break;
                }
            }
            break;
        }
        if (!changed) {
            break;  // break while
        }
    }
}

int main() {
    cin >> c >> m >> n;
    for (int i = 1; i <= m; i++) {
        int x;
        uint16_t w;
        cin >> x >> w;
        grids[x] = w;
    }
    for (int i = 1; i <= n; i++) {
        cin >> ops[i];
    }
    if (Debug) {
        cout << "c-m-n: " << c << " " << m << " " << n << endl;
        print_grids();
        print_ops();
        cout << "numWaterGrid: " << numWaterGrid() << endl;
    }
    for (int i = 1; i <= n; i++) {
        // cout << "op: " << ops[i] << endl;
        sim(ops[i]);
        numWater[i] = numWaterGrid();
    }
    for (int i = 1; i <= n; i++) {
        cout << numWater[i] << endl;
    }
}
