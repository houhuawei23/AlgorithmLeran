/*
给定序列的最大子序和

*/

#include <bits/stdc++.h>


using namespace std;

const int INF = 0x7fffffff;

int main(){
    int T; cin >> T;
    int n; 
    int a;
    
    while(T--){
        cin >> n;
        int maxsum = -INF;
        int sum = 0;
        int start = 1, end = 1; 
        // int 
        for(int p = 1; p <= n; p++){ // read each num
             cin>>a;
             sum += a;
             if (sum > maxsum) {
                 maxsum = sum;
                 end = p;
             }
             if (sum < 0) {// 放弃目前积累的
                 sum = 0;
                 start = p + 1;
                 end = p + 1;
             }
        }
        cout << "Case " << n << ":" << endl;
        cout << maxsum << " " << start << " " << end << endl;
        cout << endl;
    }
    
}