#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ull;

const ull MAXN = 1e10 + 10;

vector<ull> primes;
vector<ull> res;
int q, k;
ull n;

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
void printPrimes() {
    cout << "primes: " << endl;
    for (auto p : primes) {
        cout << p << " ";
    }
    cout << endl;
}

ull reduceFactor(ull n, const int k) {
    ull reduced = 1;
    for (auto p : primes) {
        if (p * p > n)
            break;
        int num = 0;
        ull exp = 1;
        while (n % p == 0) {
            n /= p;
            num++;
            exp *= p;
        }
        if (num >= k) {
            reduced *= exp;
        }
    }
    return reduced;
}

int main() {
    cin >> q;
    calcPrimes();
    // printPrimes();
    while (q--) {
        cin >> n >> k;
        res.push_back(reduceFactor(n, k));
    }
    for (auto r : res) {
        cout << r << endl;
    }
}

/*
3
2155895064 3
2 2
10000000000 10
*/