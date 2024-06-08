/*
约数个数
算数基本定理 + 推论
如果 N = p1^c1 * p2^c2 * ... *pk^ck
约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 110, MOD = 1e9 + 7;

unordered_map<int, int> primes;

int n;
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
  uint64_t res = 1;
  for(const auto [p, c] : primes) {
    res = res * (c + 1) % MOD;
  }
  cout << res << endl;
}