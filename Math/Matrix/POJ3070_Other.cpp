#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int MOD = 10000;
void mul(int F[2], int c[][2]) {
    int ans[2];
    memset(ans, 0, sizeof(ans));
    for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++) {
            ans[j] = (ans[j] + (ll)F[k] * c[k][j]) % MOD;
        }
    }
    memcpy(F, ans, sizeof(ans));
}
void mulself(int c[][2]) {
    int ans[2][2];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                ans[i][j] = (ans[i][j] + (ll)c[i][k] * c[k][j]) % MOD;
            }
        }
    }
    // 这里不用用sizeof(c) 因为c的大小只是一维的
    memcpy(c, ans, sizeof(ans));
}

void f(int b) {
    int F[2] = { 0, 1 };  //{F0, F1}
    int c[2][2] = { { 0, 1 }, { 1, 1 } };
    while(b) {
        if(b & 1) mul(F, c);
        mulself(c);
        b >>= 1;
    }
    printf("%d\n", F[0]);
}

int main() {
    int b;
    while(scanf("%d", &b), b != -1) {
        f(b);
    }
    return 0;
}
