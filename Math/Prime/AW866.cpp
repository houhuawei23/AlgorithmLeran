/* 试除法 i = 2...sqrt(n) 
n <= 100
a <= 2^31 - 1
100 * sqrt(2^31) = 5e6
*/

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(is_prime(x)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}