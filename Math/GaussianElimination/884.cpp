int n;
int a[N][N];
int gauss() {
    int c, r;
    for (c = 0, r = 0; c < n; c++) {
        // 找主元
        int t = -1;
        for (int i = r; i < n; i++)
            if (a[i][c]) {
                t = i;
                break;
            }
        if (t == -1)
            continue;
        // 交换主元行
        for (int j = c; j <= n; j++)
            swap(a[r][j], a[t][j]);
        // 左下角消
        for (int i = r + 1; i < n; i++)
            if (a[i][c])                      // 漏了
                for (int j = n; j >= c; j--)  // 漏了
                    a[i][j] ^= a[r][j];
        r++;
    }
    // 判断
    if (r < n) {
        for (int i = r; i < n; i++)  // i=r
            if (a[i][n])
                return 2;
        return 1;
    }
    // 消右上角
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            // 如果是0 就不用下面的a[j][j] 来^a[i][j]了
            // 如果不是0 才需要用第j行第j列a[j][j]来^第i行第j列a[i][j]
            // 进而进行整行row[i]^row[j] 间接导致 a[i][n]^a[j][n]
            if (a[i][j])
                a[i][n] ^= a[j][n];
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];
    int t = gauss();
    if (t == 0) {
        for (int i = 0; i < n; i++)
            cout << a[i][n] << endl;
    } else if (t == 1)
        puts("Multiple sets of solutions");
    else
        puts("No solution");
    return 0;
}

作者：仅存老实人
链接：https
    :  // www.acwing.com/solution/content/26544/
       来源：AcWing 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。