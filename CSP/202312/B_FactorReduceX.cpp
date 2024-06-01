#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ull;

const ull MAXN = 1e10 + 10;

vector<ull> primes;
vector<ull> results;
int q;
ull n;
int k;

ull qmi(ull a, int b) {
    ull res = 1;
    while (b) {
        if (b & 1)
            res = res * a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void calcPrimes() {
    for (ull i = 2; i * i <= MAXN; i++) {
        bool isPrime = true;
        for (auto q : primes) {
            if (i % q == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primes.push_back(i);
    }
}

ull reduceFactor(ull n, int k) {
    /* p -> num*/
    unordered_map<int, int> factors;
    ull res = 1;
    for (auto p : primes) {
        while (n % p == 0) {
            n /= p;
            factors[p]++;
        }
        if (factors[p] >= k) {
            res *= qmi(p, factors[p]);
        }
    }
    return res;
}

int main() {
    calcPrimes();
    cin >> q;
    while (q--) {
        cin >> n >> k;
        results.push_back(reduceFactor(n, k));
    }
    for (auto r : results) {
        cout << r << endl;
    }
}

/*
输入样例：
3
2155895064 3
2 2
10000000000 10
输出样例：
2238728
1
10000000000

*/