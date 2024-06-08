/*
约数个数
算数基本定理 + 推论
如果 N = p1^c1 * p2^c2 * ... *pk^ck
约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
*/

#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ull;
const int N = 110, MOD = 1e9 + 7;

unordered_map<int, int> primes;

int n;

ull qmi(ull a, ull b) {
  ull res = 1;
   /* 可能溢出, 及时 MOD */
  while(b) {
    if(b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

int main() {
  cin >> n;
  while(n--) {
    int x;
    cin >> x;
    for(int i = 2; i <= x / i; i++) {
      while(x % i == 0) {
        x /= i;
        primes[i]++;
      }
    }
    if(x > 1) primes[x]++;
  }
  ull res = 1;
  for(auto [p, c] : primes) {
    ull cur = 0;
    // printf("(p, c): (%d, %d)\n", p, c);
    for(int i = 0; i <= c; i++) {
        cur = (cur + qmi(p, i)) % MOD;
    }
    // or
    // while(c--) cur = (cur * p + 1) % MOD;
    
    // printf("cur: %ld\n", cur);

    res = (res * cur) % MOD;
  }
  cout << res << endl;
}