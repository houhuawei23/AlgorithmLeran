/*
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int a, b;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  cin >> n;
  while(n--) {
    cin >> a >> b;
    cout << gcd(a, b) << endl;
  }
}