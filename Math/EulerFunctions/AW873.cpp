/*
欧拉函数
N = p1^a1 * p2^a1 * ... * pm^am
phi(N) = N * (p1 - 1)/p1 * (p2 - 1)/p2 * ... *  (pm - 1)/pm
*/
#include <bits/stdc++.h>
using namespace std;

int n, a;

int phi(int x) {
  int res = x;
  for(int i = 2; i <= x / i; i++) {
    if(x % i == 0) {
      res = res / i * (i - 1);
      while(x % i == 0) x /= i;
    }
  }
  if(x > 1) res = res / x * (x - 1);
  return res;
  //   cout << res << endl;
}
int main() {
  cin >> n;
  while(n--) {
    cin >> a;
    cout << phi(a) << endl;
  }
}