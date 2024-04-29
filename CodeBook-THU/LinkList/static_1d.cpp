#include <bits/stdc++.h>

using namespace std;

#define N 105

int nodes[N];
// pos of id th node is id
// nodes[id] is id th node value, here is next node pos
int main(){
    int n, m; scanf("%d %d", &n, &m);
    for (int i=1; i<=n;i++){
        nodes[i] = i + 1;
    }
    nodes[n] = 1;
    int prepos = 1, nowpos = 1;
    while(n--){
        for (int i = 1; i < m; i++){
            prepos = nowpos;
            nowpos = nodes[nowpos];
        }
        printf("%d ", nowpos);
        nodes[prepos] = nodes[nowpos];
        nowpos = nodes[prepos];
    }
    return 0;
}
