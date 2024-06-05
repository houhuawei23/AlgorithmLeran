/*计数问题
https://www.acwing.com/problem/content/340/


not over.
*/
#include <bits/stdc++.h>
using namespace std;

// int a, b;
vector<int> as;
vector<int> bs;

int calcNum(int e, int pos, int n) {

}

vector<int> calcDigitalsNum(int n) {
    /* calc num of each digial in 1 to n */
    vector<int> res(10);
    for (int i = 0; i <= 9; i++) {
        for (int j = 1; j <= bitsnum; j++)
            res[i] += calcNum(i, j, n);
    }
}

void solve(int a, int b) {
    auto va = calcDigitalsNum(a - 1);
    auto vb = calcDigitalsNum(b);
    for (int i = 0; i < = 9; i++) {
        auto va[i] = vb[i] - va[i];
    }
    for (int i = 0; i <= 9; i++) {
        printf("%d ", va[i]);
    }
    printf("\n");
}

int main() {
    while (true) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0 and b == 0) {
            break;
        }
        as.push_back(a);
        bs.push_back(b);
    }
    printf("a b");
    for (int i = 0; i < as.size(); i++) {
        printf("%d %d\n", as[i], bs[i]);
    }
}