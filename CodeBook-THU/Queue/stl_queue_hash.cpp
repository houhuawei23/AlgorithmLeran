#include <bits/stdc++.h>

using namespace std;

list<int> mem;

int cnt = 0;

bool Hash[1003] = {0};

int main(){
    // 内存大小 m<=100, 查询数量 n<=1000
    int m, n; scanf("%d %d", &m, &n);
    while(n--){
        int q; scanf("%d", &q);
        if (!Hash[q]){
            cnt++;
            Hash[q] = 1;
            mem.push_back(q);
            if((int)mem.size() > m){
                int p = mem.front();
                Hash[p] = 0;
                mem.pop_front();
            }
        }
    }
    printf("%d\n", cnt);
    // printf("%lld\n", mem.max_size());
    return 0;
}

/*

std::list
1 常数时间元素插入和移除
2 不支持快速随机访问
3 可双向迭代，通常实现为双向链表

#include <list>
using namespace std;

list<int> myList;

初始化:
    std::list<int> l(cnt, val); // {val, val, ...} cnt
元素访问：
    myList.front();
    .back();
迭代器：
    .begin(), .end()
    .rbegin(), .rend()
容量：
    empty()
    size()
修改：
    clear()
    insert(it, val), insert(it, cnt, val), insert(it, it1, it2)
    insert(it, p1, p2), insert(it, {1,2,3})
    emplace(pos, args) // construct inplace
    erase(posit), erase(first_it, last_it)
    push_back(val), emplace_back(val)
    pop_back() // return NULL
    push_front(val), emplace_front() 
    pop_front() 
    swap(list& other) 
    // 将容器的内容与其他容器的内容交换。不对单个元素调用任何移动、复制或交换操作。
操作:
    .merge(list& other)
    .splice()
    remove()
    reverse()
    unique()
    .sort(), .sort(std::greater<int>())

*/



















