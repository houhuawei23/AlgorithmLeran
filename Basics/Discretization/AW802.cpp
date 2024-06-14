/*
离散化的本质是建立了一段数列到自然数之间的映射关系（value -> index)，
通过建立新索引，来缩小目标区间，使得可以进行一系列连续数组可以进行的操作,
比如二分，前缀和等…

离散化首先需要排序去重：

1. 排序：sort(alls.begin(),alls.end())
2. 去重：alls.earse(unique(alls.begin(),alls.end()),alls.end());
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];

vector<int> alls;  // 存入下标容器
vector<PII> add, query;
// add增加容器，存入对应下标和增加的值的大小
// query存入需要计算下标区间和的容器
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while(l < r)  // 查找大于等于x的最小的值的下标
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;  // 因为使用前缀和，其下标要+1可以不考虑边界问题
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({ x, c });  // 存入下标即对应的数值c

        alls.push_back(x);  // 存入数组下标x=add.first
    }

    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({ l, r });  // 存入要求的区间

        alls.push_back(l);  // 存入区间左右下标
        alls.push_back(r);
    }

    // 区间去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 处理插入
    for(auto item : add) {
        int x = find(item.first);
        // 将add容器的add.secend值存入数组a[]当中，
        a[x] += item.second;
        // 在去重之后的下标集合alls内寻找对应的下标并添加数值
    }

    // 预处理前缀和
    for(int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    // 处理询问
    for(auto item : query) {
        int l = find(item.first), r = find(item.second);
        // 在下标容器中查找对应的左右两端[l~r]下标，然后通过下标得到前缀和相减再得到区间a[l~r]的和
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}

/*
作者：yxc
链接：https://www.acwing.com/activity/content/code/content/40105/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/