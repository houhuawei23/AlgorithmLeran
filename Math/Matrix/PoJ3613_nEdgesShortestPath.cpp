/* Cow Relays
https://vjudge.net/problem/POJ-3613
N Edges Shortest Path, General Matrix Mul, Matrix Fast Power
Input
2 6 6 4
11 4 6
4 4 8
8 4 9
6 6 8
2 6 9
3 8 9
Output
10
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int INF = 0x3f;
const int N = 120;
int Hash[1010], cnt = 0;
struct Matrix {
    int data[N][N];
    Matrix() { memset(data, INF, sizeof(data)); }
    Matrix operator*(const Matrix& rhs);
    Matrix power(int k) const;
    void print() const;
};

Matrix Matrix::operator*(const Matrix& b) {
    Matrix& a = *this;
    Matrix c;
    for(int i = 1; i <= cnt; i++) {
        for(int j = 1; j <= cnt; j++) {
            for(int k = 1; k <= cnt; k++) {
                c.data[i][j] = min(c.data[i][j], a.data[i][k] + b.data[k][j]);
            }
        }
    }
    return c;
}
Matrix Matrix::power(int k) const {
    Matrix tmp = *this;
    Matrix ans = *this;
    k--;
    while(k) {
        if(k & 1) ans = ans * tmp;
        tmp = tmp * tmp;
        k >>= 1;
    }
    return ans;
}
void Matrix::print() const {
    cout << "matrix: " << endl;
    for(int i = 1; i <= cnt; i++) {
        for(int j = 1; j <= cnt; j++) {
            if(data[i][j] == 0x3f3f3f3f) {
                cout << "i" << " ";
            } else {
                cout << data[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void print_hash() {
    cout << "Hash: " << endl;
    for(int i = 1; i <= 10; i++) {
        cout << i << ": " << Hash[i] << endl;
    }
}
int main() {
    int N, T, S, E;
    cin >> N >> T >> S >> E;
    Matrix m;
    while(T--) {
        int l, a, b;
        cin >> l >> a >> b;
        if(Hash[a] == 0) Hash[a] = ++cnt;
        if(Hash[b] == 0) Hash[b] = ++cnt;
        m.data[Hash[a]][Hash[b]] = m.data[Hash[b]][Hash[a]] = l;
    }
    // print_hash();
    // m.print();
    Matrix ans = m.power(N);
    // ans.print();
    cout << ans.data[Hash[S]][Hash[E]] << endl;
}