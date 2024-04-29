/*
hdu 2602
*/

/*
#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1005;

int Ws[NMAX]; // 价值
int Cs[NMAX]; // 体积
int f[NMAX][NMAX];

int main(){
    int CNT; cin >> CNT;
    int n, c;
    while(CNT--){
        cin >> n >> c;
        for (int i = 1; i <= n; i++) {
            cin >> Ws[i];
        }
        for (int i = 1; i<=n; i++) {
            cin >> Cs[i];
        }
        memset(f, 0, sizeof(f));

        for (int i=1; i<=n; i++){
            for(int j=0; j<=c; j++){ // j start from 0
                f[i][j] = f[i-1][j];
                if (j >= Cs[i]) f[i][j] = max(f[i][j], f[i-1][j-Cs[i]] + Ws[i]);
            }
        }
        cout << f[n][c] << endl;
    }

}
*/
#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1005;

int Ws[NMAX]; // 价值
int Cs[NMAX]; // 体积
int f[NMAX];

int main(){
    int CNT; cin >> CNT;
    int n, c;
    while(CNT--){
        cin >> n >> c;
        for (int i = 1; i <= n; i++) {
            cin >> Ws[i];
        }
        for (int i = 1; i<=n; i++) {
            cin >> Cs[i];
        }
        memset(f, 0, sizeof(f));

        for (int i=1; i<=n; i++){
            for(int j=c; j>=Cs[i]; j--){ 
                f[j] = max(f[j], f[j-Cs[i]] + Ws[i]);
            }
        }
        cout << f[c] << endl;
    }

}