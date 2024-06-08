/*
合并果子
https://www.acwing.com/problem/content/150/
Huffman Tree or priority queue

合并n堆果子, 每次合并任取两堆, 体力耗费等于两堆数量之和, 求方案使体力耗费最小. N
<= 1e4 相似题目: 合并石子, 只能合并相邻两堆, N <= 300

贪心,哈夫曼树,堆,优先队列) O(nlogn)
每次合并最小的两堆!
使用小根堆维护所有果子，每次弹出堆顶的两堆果子，并将其合并，合并之后将两堆重量之和再次插入小根堆中。
每次操作果子堆数-1, n-1次减为1, 每次操作涉及到对heap的2次删除与1次插入, 每次 log n
n logn
输入样例：
3
1 2 9
输出样例：
15

Definition:
设二叉树具有 n 个带权叶结点，
从根结点到各叶结点的路径长度与相应叶节点权值的乘积之和称为
树的带权路径长度（Weighted Path Length of Tree，WPL）。

对于给定一组具有确定权值的叶结点，可以构造出不同的二叉树，
其中，WPL 最小的二叉树 称为 霍夫曼树（Huffman Tree）。

对于霍夫曼树来说，其叶结点权值越小，离根越远，
叶结点权值越大，离根越近，此外其仅有叶结点的度为 0，其他结点度均为 2。

*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 10;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> heap;
    while(n--) {
        int a;
        cin >> a;
        heap.push(a);
    }
    int res = 0;
    while(heap.size() > 1) {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        res += (a + b);
        heap.push(a + b);
    }
    cout << res << endl;
}