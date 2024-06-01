#include <bits/stdc++.h>

using namespace std;

// const int N = 1e9+2;
const int N = 1e3+2;
const int P = 1e5+2;

// int posx[P], posy[P]; // p 个人的位置
int Map[N][N];

// int tmp[P]; // index of di
//           0  1  2   3   4   5   6   7
int Dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
int Dy[8] = {0 ,1, 1,  1,  0, -1, -1, -1}; // 


int n,m,p,q; 
int u, v, t; // 龙的位置
int x, y;

void check();
void print_map();

int main() {
    // n*m 棋盘大小 1e9， p个员工，q次探查 1e5

    cin>>n>>m>>p>>q;
    for (int i = 1; i <= p; i++) {
        cin >> x >> y;
        Map[x][y] = i;
    }
    print_map();

    for (int i = 1; i <= q; i++) {
        // 第i次探查，每次探查后都要更新所有员工的位置
        check();
        print_map();
    } // 第i次探查结束
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(Map[i][j]) {
                res ^= Map[i][j] * i + j;
            }
        }
    }
    
    cout << res << endl;
    return 0;
}

void check() {
    // 第i次探查，每次探查后都要更新所有员工的位置
    cin >> u >> v >> t;
    // 计算出 k
    // K1
    // int mink1 = INT_MAX;
    // 遍历8个方向
    int k1 = INT_MAX; // 所有方向后的k
    for (int di=0; di < 8; di++) {
        // int dx = Dx[di];
        // int dy = Dy[di];
        int tk = 1; // ++
        int tx = u+ Dx[di]*tk;
        int ty = v+ Dy[di]*tk;
        while ((tx<=n)&&(tx>=1)&&(ty<=m)&&(ty>=1)) { // 没有超出边界
            if (Map[tx][ty]) { // !0 代表有人
                // 第一次进入，一定就是最近的那个吗？
                // 该方向最近，但不是所有方向最近
                k1 = min(k1, tk);
                // cout << "di: " << di << endl;
                break; // break while 
            }
            tk++;    // ++
            tx = u+Dx[di]*tk;
            ty = v+Dy[di]*tk;
        }
        
    }
    // get k1
    // cout << "k1: " << k1 << endl;
    
    // K2
    int k2 = min({n-u, m-v, u, v});
    int k = 0;
    if (k1 <= k2) {
        k = k1;
    }
    // cout << "k2, k: " << k2 << ", " << k << endl;

    if (k > 0) { // 更新所有（8各方位上k距离处的）员工的位置
        int tmp[8];
        for (int di=0; di < 8; di++) {
            int tx = u + Dx[di]*k;
            int ty = v + Dy[di]*k;
            int ndi = (di+t)%8;
            tmp[ndi] = Map[tx][ty];


            
        }
        for (int di=0; di <8; di++) {
            int tx = u + Dx[di]*k;
            int ty = v + Dy[di]*k;
            Map[tx][ty] = tmp[di];
            
        }
        
    } // if k > 0
    

}


void print_map() {
    for (int row = 1; row <= m; row++){
        for (int col = 1; col <= n; col++) {
            cout << Map[col][m-row+1];
            if (col == u && (m-row+1==v)) {
                cout << "*";
            }
            else {
                cout << " ";
            }
            
        }
        cout << endl;
    }
    cout << endl;
}











