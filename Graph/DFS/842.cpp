#include <bits/stdc++.h>

using namespace std;

int n;
void f(vector<int> v) {
    // cout << "f";

    // for (auto e : v) {
    //     cout << e << " ";
    // }
    // cout << endl;
    if (v.size() == n) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (count(v.begin(), v.end(), i))
            continue;
        // cout << "i " << i << endl;
        vector<int> vv = v;
        vv.push_back(i);
        f(vv);
    }
}
int main() {
    cin >> n;
    vector<int> v;
    f(v);
}

/*
in
3
out
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/