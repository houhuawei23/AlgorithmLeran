#include <bits/stdc++.h>

using namespace std;

list<int> mem;

int cnt = 0;

bool inMem(int q){
    for(auto it = mem.begin(); it != mem.end(); it++){
        if(*it == q) return true;
    }
    return false;
}

int main(){
    int m, n; scanf("%d %d", &m, &n);
    while(n--){
        int q; scanf("%d", &q);
        if (!inMem(q)){
            cnt++;
            mem.push_back(q);
            if((int)mem.size() > m){
                mem.pop_front();
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}