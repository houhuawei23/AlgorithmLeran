/*
背包模型

1 将问题转换为01背包模型
书本的总价格>=x并且 最小
可以将问题理解为 选取几本书使得书本的总价格<= sum - x的情况下，使得书本的总价格最大

2 整个问题也可以看作是01背包问题
从前i本书中选择要被减掉的书，使得总价格>= x的所有选法
求所有选法集合中的价格最小值即是答案

*/


/*
#include <bits/stdc++.h>

using namespace std;


const int N = 35;
const int M = 300005;

int arr[N];
int f[N][M];

int main(){
    int n, x; cin >> n >> x;
    int SUM = 0;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        SUM += arr[i];
    }
    int c = SUM - x;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (j >= arr[i]){
                f[i][j] = max(f[i-1][j], f[i-1][j-arr[i]] + arr[i]);
            }
            else {
                f[i][j] = f[i-1][j];
            }
            
            
            // f[i][j] = f[i-1][j];
            // if (j >= arr[i]) f[i][j] = max(f[i][j], f[i-1][j-arr[i]] + arr[i]);
        }
    }
    // cout << "SUM, c, f[n][c]: " << SUM << ", " << c << ", "<< f[n][c] <<endl;
    cout << SUM - f[n][c] << endl;
    
}
*/
/*

#include <bits/stdc++.h>
using namespace std;

const int N = 31;
const int M = 300005;

int arr[N];
int f[M];

int main(){
    int n, x; cin >> n >> x;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int c = sum - x;
    for (int i = 1; i <= n; i++) {
        for (int j = c; j>=arr[i]; j--) {
            f[j] = max(f[j], f[j-arr[i]] + arr[i]);
        }
    }
    cout << sum - f[c];
}
*/


/*
f(i, j):
集合: 
    元素: 从 1~i 中选择若干本书，作为不要的书，每种可能的选法为一个元素
    条件: 选定不要的书后，1~i 中剩余的书 和 i+1~n所有的书 的总额 >= j
    满足上述要求和条件的所有可能的选法构成的集合
f(i, j)代表的集合属性:
    所有去除选法对应的付款金额中的最小值 min
    每种满足条件的去除选法对应一个付款金额，f(i, j)是所有满足条件的去除选法的付款金额的最小值

递推计算:
首先分析base情况:
    f(0, j) 代表从 1~0 中选去除的书，选法的付款金额 >= j，中的付款金额的最小值
        即要购买 1~n 所有的书，付款金额为定值 SUM，则:
        forall j in 0 ~ SUM, f(0, j) = SUM
    f(i, SUM) 代表从 1~i 中选要去除的书，可能选法的付款金额 >= SUM，最小付款金额
        显然，1~i 中一本也不能去除，才能保证 总付款额 == SUM，则:
        forall i in 0 ~ n, f(i, SUM) = SUM

绘出 f 表格图可知，f(i, j)的递推式是“右上到左下”的。
最终的结果就是 f(n, x)，即从 1~n 中选要去除的书，保证总付款金额 >= x

划分 f(i, j) 代表的集合
    1 只从 1~i-1中选要去除的书，付款金额 >= j
        f(i-1, j)
    2 一定选上 i 作为去除的书，付款金额 >= j，满足要求的选法构成一个集合
        将该集合中所有的选法 删去 i，则得到的新的选法构成的集合与原集合一一对应
        该新集合要满足的要求是: 从 1~i-1 选要去除的书，付款额 >= j + arr[i]
        (因为一定会去除 i，即 -arr[i]，所以前 i-1 本书只需要满足付款我 >= j + arr[i])
        则这部分的最小付款额为: 
        f(i-1, j + arr[i]) - arr[i]
    两者取最小即可
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 35;
const int M = 3e5 + 5;

int arr[N];
int f[N][M];

int main(){
    int n, x; cin >> n >> x;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i <= n; i++) {
        f[i][sum] = sum;
    }
    for (int j = 0; j <= sum; j++) {
        f[0][j] = sum;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= x; j--) {

            if (j + arr[i] <= sum) {
                f[i][j] = min(f[i-1][j], f[i-1][j + arr[i]] - arr[i]); 
            }
            else {
                f[i][j] = f[i-1][j];
            }
        }
    }
    
    cout << f[n][x] << endl;
}


























