/*
dp解决
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    // int tmp = INT_MIN;
    
    // cout << max(1, 2);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int start = 1, end = 1;
        int maxsum = INT_MIN;
        int dp1 = 0, dp2 = 0;
        int a;
        for (int p = 1; p <= N; p++){
            cin >> a;
            dp2 = max(a, dp1 + a);
            maxsum = max(dp2, maxsum);
            dp1 = dp2;
            // cout << "a, dp2, maxsum: " <<a << ", " << dp2 << ", " << maxsum << endl;
            // cout << "dp1 + a: " << dp1 + a << endl;
        }
        cout << maxsum << endl;
    }
    
}