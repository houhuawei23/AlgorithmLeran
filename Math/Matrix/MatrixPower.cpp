#include <bits/stdc++.h>
using namespace std;

const int N = 105;

struct Matrix {
    /* n rows, m cols */
    int n, m;
    int data[N][N];
    Matrix(int rows, int cols) : n(rows), m(cols) {}
    Matrix operator*(const Matrix& rhs);
    Matrix pow_matrix(int k);
    void print();
    void read();
};

void Matrix::print() {
    assert(n != 0 and m != 0);
    cout << "matrix: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
void Matrix::read() {
    assert(n != 0 and m != 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> data[i][j];
        }
    }
}
Matrix Matrix::operator*(const Matrix& rhs) {
    assert(m == rhs.n);
    Matrix c(n, rhs.m);
    memset(c.data, 0, sizeof(c.data));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < rhs.m; j++) {
            for(int k = 0; k < m; k++) {
                c.data[i][j] += data[i][k] * rhs.data[k][j];
            }
        }
    }
    return c;
}
/*
Matrix Matrix::operator*(const Matrix& a, const Matrix& b) {
    assert(a.n = b.m);
    Matrix c;
    memset(c.data, 0, sizeof(c.data));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
}
*/

Matrix Matrix::pow_matrix(int k) {
    assert(n == m);
    Matrix a = *this; /* copy */
    Matrix ans(n, n);
    memset(ans.data, 0, sizeof(ans.data));

    for(int i = 0; i < n; i++) ans.data[i][i] = 1;

    while(k) {
        if(k & 1) ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans;
}

int main() {
    int n, power;
    cin >> n >> power;
    Matrix ma(n, n);
    ma.read();
    ma.print();
    auto ma2 = ma.pow_matrix(power);
    ma2.print();
    ma.print();
}

/*
n
n x n
data
data x data

n data
n x n
^data

2 2
1 1
1 1

*/