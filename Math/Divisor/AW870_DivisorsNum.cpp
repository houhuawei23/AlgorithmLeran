/*约数个数
https://www.acwing.com/problem/content/872/
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// set<int> divisors;
int cnt;
int n;
uint64_t mul = 1;
void get_divisors(uint64_t x) {
  for(uint64_t i = 1; i <= x / i; i++) {
    if(x % i == 0) {
      //   divisors.insert(i);
      cnt = (cnt + 1) % MOD;
      if(i != x / i) {
        cnt = (cnt + 1) % MOD;
      }
    }
  }
}


int main() {
  cin >> n;
  while(n--) {
    int a;
    cin >> a;
    mul *= a;
  }
  get_divisors(mul);
  cout << cnt << endl;
}