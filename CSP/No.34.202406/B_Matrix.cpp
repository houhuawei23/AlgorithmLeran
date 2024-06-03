/*
Not Correct.

input:
2 3 3
a b c
d e f
1 3 2
2 0 0
3 1 0

2 3 6
a b c
d e f
1 3 2
2 0 0
3 1 0
1 3 2
2 0 0
3 1 0


2 3 9
a b c
d e f
1 3 2
2 0 0
3 1 0
1 1 6
2 0 0
1 6 1
2 0 0
2 0 0
1 6 1


n m t: n x m, t operations
1 p q: reshape to p x q
2 0 0: transpose
3 i j: print M[i][j]
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
const int MAXT = 1e5 + 10;
bool debug = true;
struct Matrix {
    char M[MAXN];
    int n, m; /* n x m */
    int delta = 1;
    int num() const { return n * m; }
    void reshape(int p, int q) {
        assert(n * m == p * q);
        n = p, m = q;
    }
    void transpose() {
        if (delta * m < num()) {
            delta *= m;
        } else {
            delta = (delta * m + 1) % num();
        }
        // delta = (delta * m) % (num() - 1);
        swap(n, m);
    }
    char get(int i, int j) const {
        int idx = (delta * (i * m + j)) % (num() - 1);
        return M[idx];
    }
    void print() const {
        if (debug)
            cout << "n m delta: " << n << " " << m << " " << delta << endl;
        int idx = 0, cnt = 0;
        int base = 0;
        while (cnt < n * m) {
            cout << M[idx] << " ";
            // idx = (idx + delta) % (num() - 1);
            if (idx + delta < num()) {
                idx = idx + delta;
            } else {
                /* idx + delta >= num() */
                idx = (idx + 1 + delta) % num();
            }
            cnt++;
            if (cnt % m == 0) {
                cout << endl;
            }
        }
    }
} matrix;

int n, m, t;
int num;
int ops[MAXT][3];

int main() {
    cin >> matrix.n >> matrix.m >> t;
    for (int i = 0; i < matrix.num(); i++) {
        cin >> matrix.M[i];
    }
    for (int i = 0; i < t; i++) {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    }

    for (int i = 0; i < t; i++) {
        int op = ops[i][0], a = ops[i][1], b = ops[i][2];
        if (debug) {
            cout << "op a b: " << op << " " << a << " " << b << endl;
            cout << "before: " << endl;
            matrix.print();
        }

        switch (op) {
            case 1:
                cout << "reshape(" << a << ", " << b << ")\n";
                matrix.reshape(a, b);
                break;
            case 2:
                /* transpose */
                cout << "transpose\n";
                matrix.transpose();
                break;
            case 3:
                cout << matrix.get(a, b) << endl;
            default:
                break;
        }
        if (debug) {
            cout << "after: " << endl;
            matrix.print();
        }
        cout << endl;
    }
}