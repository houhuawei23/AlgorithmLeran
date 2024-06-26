#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int uLL;

// const uLL N = 1e5 + 10;
const uLL MAXN = 1e10 + 10;

vector<uLL> primes;
vector<uLL> results;

uLL calc(uLL n, int k);

int main() {
    // cout << N << endl;
    // preprocess

    for (uLL i = 2; i * i< MAXN; i++) {
        bool is_prime = true;
        for (auto p : primes) {
            // if (i * p >= N) break;
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
            // cout << i << endl;
        }
    }
    // cout << "primes: \n";
    // for (auto p : primes) {
    //     cout << p << " ";
    // }
    // cout << endl;
    // calc(2155895064, 3);
    int q;
    long long int n, k;
    cin >> q;
    while (q--) {
        cin >> n >> k;
        // cout << n << k << endl;
        results.push_back(calc(n, k));
    }
    for (auto ans : results) {
        cout << ans << endl;
    }
}
uLL calc(uLL n, int k) {
    uLL ans = 1;
    for (auto p : primes) {
        int cnt = 0;
        uLL tmp = 1;
        // if (p * p > n)
        //     break;
        while (n % p == 0) {
            n /= p;
            tmp *= p;
            cnt++;
        }
        if (cnt >= k) {
            ans *= tmp;
        }
    }
    // cout << ans << endl;
    return ans;
}
