#pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;

int n, m;

struct Op{
    int opn;
    double a;
};

struct Op ops[100005];

int qs[100005][4];

void read(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        // struct Op op;

        cin >> ops[i].opn >> ops[i].a;
        // cout << ops[i].opn << " " << ops[i].a << endl;
    }
    for (int i=1; i <= m; i ++){
        cin >> qs[i][0] >> qs[i][1] >> qs[i][2] >> qs[i][3];
        // cout << qs[i][0] << " "<< qs[i][1] << " "<< qs[i][2] << " "<< qs[i][3]<<endl;
    }

}

void cal(int qid){

    // cout << qs[qid][0] << " "<< qs[qid][1] << " "<< qs[qid][2] << " "<< qs[qid][3]<<endl;

    int i = qs[qid][0];
    int j = qs[qid][1];
    double x = (double)qs[qid][2];
    double y = (double)qs[qid][3];
    // cout << "qid: " << qid << endl;
    // cout << "i, j: "<< i << " " << j << endl;
    // cout << "x, y: " << x << " " << y << endl;
    for (int l = i; l <=j; l ++){
        double a = ops[l].a;
        if (ops[l].opn == 1) {
            // cout << "opn: "<< ops[l].opn << endl;
            x = a * x;
            y = a * y;

        }else if (ops[l].opn == 2) {
            // cout << "opn: "<< ops[l].opn << endl;
            double x0 = x;
            double y0 = y;
            x = x0 * cos(a) - y0 * sin(a);
            y = x0 * sin(a) + y0 * cos(a);
        }

    }
    // cout <<  x << " " << y <<endl;

    // cout << setprecision(4) << x << " " << y <<endl;
    printf("%f %f\n", x, y);
}

int main(){
    read();
    for (int i = 1; i <=m; i++){
        cal(i);
    }
}
