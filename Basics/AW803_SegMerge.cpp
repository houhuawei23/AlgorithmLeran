/* 区间合并
n <= 1e5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<pii> nums, res;
int main() {
    int st = -2e9, ed = -2e9;  // ed代表区间结尾，st代表区间开头
    int n;
    scanf("%d", &n);
    while(n--) {
        int l, r;
        scanf("%d%d", &l, &r);
        nums.push_back({ l, r });
    }
    sort(nums.begin(), nums.end());  // 按左端点排序
    for(auto num : nums) {
        if(ed < num.first)  // 情况1：两个区间无法合并
        {
            if(ed != -2e9) res.push_back({ st, ed });  // 区间1放进res数组
            st = num.first, ed = num.second;           // 维护区间2
        }
        // 情况2：两个区间可以合并，且区间1不包含区间2，区间2不包含区间1
        else if(ed < num.second)
            ed = num.second;  // 区间合并
    }
    //(实际上也有情况3：区间1包含区间2，此时不需要任何操作，可以省略)

    // 注：排过序之后，不可能有区间2包含区间1

    res.push_back({ st, ed });

    // 考虑循环结束时的st,ed变量，此时的st,ed变量不需要继续维护，只需要放进res数组即可。
    // 因为这是最后的一个序列，所以不可能继续进行合并。

    /*
    for(auto r:res)
        printf("%d %d\n",r.first,r.second) ;
    puts("") ;
    */

    //(把上面的注释去掉，可以在调试时用)

    printf("%d", res.size());  // 输出答案
    return 0;
}
/*
作者：lixiaoqian_qwq
链接：https://www.acwing.com/solution/content/2615/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/