/*
作者：这道题有点难耶
链接：https://www.acwing.com/solution/content/211921/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

定义一个类来存储多项式

多项式中的每一项是一个长度为n+1的vector，第0位是这一项的系数，第1~n项是第i个自变量的次数，则多项式就是vector的vector
多项式乘法：两个多项式的每一项分别相乘，两个项相乘的规则是：系数相乘，对应自变量的次数相加。
多项式加法：直接把两个多项式的项存到一个多项式里。
多项式减法：在存储中，各项之间是加法。则减法就是作为减数的多项式的每一项系数变成相反数，然后做加法。
多项式求偏导：每一项只有一个是自变量，其他的是常数，那求导的过程就是自变量次数减1，系数=系数*次数
多项式求值：遍历每一项，系数为0则跳过，不为0时用快速幂求每一个乘方，项内相乘，各项的乘积相加


*/

#define LOCAL
#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define debug(x) cerr << #x << ' ' << '=' << ' ' << x << endl
#else
#define dbg(...)
#define debug(x)
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9 + 7;
int n, m;

ll qmi(ll a, int k) {
    ll res = 1;
    while(k) {
        if(k & 1) res = res * a % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return res % mod;
}

struct Poly {
    vector<vector<ll>> f;
    Poly() : f{} {}
    Poly(int x) {
        vector<ll> a(n + 1, 0);
        a[0] = x;
        f.push_back(a);
    }
    Poly(string str) {
        int ind = stoi(str.substr(1));
        vector<ll> a(n + 1, 0);
        a[0] = 1, a[ind] = 1;
        f.push_back(a);
    }
    Poly operator*(const Poly& w) const {
        Poly res;
        for(auto& x : f) {
            for(auto& y : w.f) {
                vector<ll> t(n + 1, 0);
                t[0] = (x[0] * y[0]) % mod;
                for(int i = 1; i <= n; i++) t[i] = x[i] + y[i];
                res.f.push_back(t);
            }
        }
        return res;
    }
    Poly operator+(const Poly& w) const {
        Poly res;
        res.f = f;
        for(auto& x : w.f) res.f.push_back(x);
        return res;
    }
    Poly diff(int ind) {
        Poly res;
        for(auto& x : f) res.f.push_back(x);
        for(auto& vec : res.f) {
            vec[0] = (vec[0] * vec[ind]) % mod;
            vec[ind]--;
        }
        return res;
    }
    ll eval(vector<int>& v) {
        ll sum = 0;
        for(auto& vec : f) {
            int res = vec[0];
            if(!res) continue;
            for(int i = 1; i <= n; i++)
                res = (res * qmi(v[i - 1], vec[i])) % mod;
            sum = (sum + res) % mod;
        }
        return ((sum % mod) + mod) % mod;
    }
    void print() {
        for(auto& x : f) {
            for(auto& y : x) cerr << y << ' ';
            cerr << "\n";
        }
    }
};
stack<Poly> val;

void calc(string str) {
    Poly a = val.top();
    val.pop();
    Poly b = val.top();
    val.pop();
    if(str == "*")
        val.push(a * b);
    else if(str == "+")
        val.push(a + b);
    else {
        for(auto& x : a.f) x[0] = -x[0];
        val.push(a + b);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    string formula;
    cin.get();
    getline(cin, formula);

    stringstream oss(formula);
    string str;
    while(oss >> str) {
        if(str[0] == 'x') {
            Poly a(str);
            val.push(a);
        } else if(str == "*" || str == "+" || str == "-")
            calc(str);
        else {
            Poly a(stoi(str));
            val.push(a);
        }
    }
    Poly ff = val.top();
    while(m--) {
        vector<int> t(n, 0);
        int ind;
        cin >> ind;
        for(int i = 0; i < n; i++) cin >> t[i];
        Poly tt = ff.diff(ind);
        cout << tt.eval(t) << "\n";
    }
    return 0;
}
