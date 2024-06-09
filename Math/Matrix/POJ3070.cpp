/* Fibonacci
Matrix Fast Power.
0
9
999999999
1000000000
-1

0
34
626
6875
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 2;
const int MOD = 1e4;

struct Matrix {
    // int rows, cols;
    int data[N][N];
    Matrix() { memset(data, 0, sizeof(data)); };
    /* c++ 11 */
    // Matrix(const initializer_list<int>& init) {
    //     memset(data, 0, sizeof(data));
    //     int rows = 0, cols = 0, cnt = 0;
    //     for(auto e : init) {
    //         data[rows][cols] = e;
    //         cnt++;
    //         if(cnt % N == 0) {
    //             rows++, cols = 0;
    //         } else {
    //             cols++;
    //         }
    //     }
    // }
    Matrix operator*(const Matrix& rhs);
    Matrix power(int k);
    void print();
};

Matrix Matrix::operator*(const Matrix& rhs) {
    Matrix ans;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                ans.data[i][j] =
                    (ans.data[i][j] + data[i][k] * rhs.data[k][j]) % MOD;
            }
        }
    }
    return ans;
}
Matrix Matrix::power(int k) {
    Matrix a = *this;
    Matrix ans;
    for(int i = 0; i < N; i++) ans.data[i][i] = 1;
    while(k) {
        if(k & 1) ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans;
}
void Matrix::print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    // Matrix A = { 1, 1, 1, 0 }; /* c++ 11 */
    Matrix A;
    A.data[0][0] = 1, A.data[0][1] = 1, A.data[1][0] = 1;
    // A.print();
    while(cin >> n, n != -1) {
        // cout << n << endl;
        Matrix F = A.power(n);
        // cout << "Fn: " << F.data[0][1] << endl;
        cout << F.data[0][1] << endl;
    }
}