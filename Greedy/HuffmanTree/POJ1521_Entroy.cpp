#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > q;
    string s;
    while(getline(cin, s) && s != "END") {
        sort(s.begin(), s.end());
        int num = 1;
        int i = 0, j = 0;
        while(j <= s.length()) {
            if(s[j] == s[i]) {
                j++;
            } else {
                int n = j - i;
                // cout << s[i] << ": " << n << endl;
                i = j;
                q.push(n);
            }
        }
        int ans = 0;
        if(q.size() == 1) ans = s.length();
        while(q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a + b);
            ans += a + b;
        }
        q.pop();
        printf("%d %d %.1f\n", (int)s.length() * 8, ans,
               (double)s.length() * 8 / (double)ans);
        // for(int i = 1; i <= s.length(); i++) {
        //     if(s[i] != s[i - 1]) {
        //         cout << s[i - 1] << ": " << num << endl;
        //         q.push(num), num = 1;
        //     } else {
        //         num++;
        //     }
        // }
    }
}
/*
AAAAABCD
THE_CAT_IN_THE_HAT
END
*/