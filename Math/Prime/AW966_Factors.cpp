/* 
分解质因数
试除法 N <= 100
是否有更高效的方法?

*/

#include <bits/stdc++.h>

using namespace std;
void divide(int x) {
    for(int i = 2; i <= x / i; i++) {
        if(x % i == 0) {
            int s = 0;
            while(x % i == 0) {
                s++;
                x /= i;
            }
            cout << i << " " << s << endl;
        }
    }
    if(x > 1) {
        cout << x << " " << 1 << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        divide(x);
    }
    return 0;
}