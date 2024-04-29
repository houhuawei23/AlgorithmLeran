/*
std::queue
front()
back()

empty()
size()

push()
pop()
swap()
*/

#include <bits/stdc++.h>

using namespace std;

queue<int> mem;

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
            mem.push(q);
            if((int)mem.size() > m){
                Hash[mem.front()] = 0;
                mem.pop();
            }
        }
    }
    printf("%d\n", cnt);
    // printf("%lld\n", mem.max_size());
    return 0;
}
