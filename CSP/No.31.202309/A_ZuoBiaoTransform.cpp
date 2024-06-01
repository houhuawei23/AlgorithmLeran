#include <bits/stdc++.h>

using namespace std;

int dx, dy = 0;
int Dx, Dy = 0;
int X[101], Y[101];

int main(){
    int n, m;
    cin >> n >> m;
    while (n--){
        cin >> dx >> dy;
        Dx += dx;
        Dy += dy;
    }

    for (int i=0; i<m; i++){
        cin >> X[i] >> Y[i];
    }

    for (int i=0; i<m; i++){
        cout << X[i] + Dx << " " << Y[i] + Dy << endl;
    }

    
}