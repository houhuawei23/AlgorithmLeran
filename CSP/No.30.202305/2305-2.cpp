#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;

const int MAXN = 10005;
const int MAXD = 25;
// #define MAXN 10005
// #define
ll Q[MAXN][MAXD];
ll K[MAXN][MAXD];
ll V[MAXN][MAXD];
ll W[MAXN];

int n, d;

void read() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> Q[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> K[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> V[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }
}

void print_matrix(ll M[MAXN][MAXD], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    // cout << endl;
}

void print_matrix(ll M[MAXD][MAXN], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    // cout << endl;
}
void reverse_matrix(ll M[MAXN][MAXD], ll R[MAXD][MAXN], int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            R[i][j] = M[j][i];
        }
    }
}

void jucheng(ll Q[MAXN][MAXD], ll rK[MAXD][MAXN], ll R[MAXN][MAXN]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll sum = 0;
            for (int k = 0; k < d; d++) {
                sum += Q[i][k] * B[k][j];
            }
            R[i][j] = sum;
        }
    }
}

int main() {
    // cout << MAXN;
    cin >> n >> d;
    read();
    cout << "Q" << endl;
    print_matrix(Q, n, d);
    ll rK[MAXD][MAXN];
    reverse_matrix(K, rK, n, d);
    cout << "K" << endl;
    print_matrix(K, n, d);
    cout << "rK" << endl;
    print_matrix(rK, d, n);
}