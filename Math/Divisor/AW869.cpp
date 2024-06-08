/* 试除法求约数 */
#include <bits/stdc++.h>
using namespace std;

vector<int> get_divisors(int x) {
    vector<int> divisors;
    for(int i = 1; i <= x / i; i++) {
        if(x % i == 0) {
            divisors.push_back(i);
            if(i != x / i) divisors.push_back(x / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        auto res = get_divisors(x);
        for(auto e : res) {
            cout << e << " ";
        }
        cout << endl;
    }
}