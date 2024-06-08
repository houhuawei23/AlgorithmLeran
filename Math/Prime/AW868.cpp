/*
筛质数
1 ~ n中质数的个数
n <= 1e6
若用试除法判定质数, 则计算量为: 1e6 * sqrt(1e6) = 1e9 TLE
必须使用筛法: O(N)
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
int num;
int primes[N];
bool st[N]; /* true is not prime, */

void get_primes(int n) {
    /* get primes <= n */
    for(int i = 2; i <= n; i++) {
        if(st[i]) continue;
        /* is  prime */
        primes[num++] = i;
        // printf("prime %d: %d\n", num, i);
        for(int j = i + i; j <= n; j += i) {
            st[j] = true;
        }
    }
}

int main() {
    cin >> n;
    get_primes(n);
    cout << num << endl;
}