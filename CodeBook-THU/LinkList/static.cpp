/*
luogu P1996 约瑟夫问题
模拟
结构体数组实现单向静态链表
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

struct node {
    int id;
    int nextpos;
}nodes[N];


int main(){
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i < n ;i++){
        nodes[i].id = i;
        nodes[i].nextpos = i + 1;
    }
    nodes[n].id = n;
    nodes[n].nextpos = 1;

    int prepos = 1, nowpos = 1;
    while ((n--)>1){
        for (int i=1; i<m; i++){
            prepos = nowpos;
            nowpos = nodes[nowpos].nextpos;
        }
        printf("%d ", nodes[nowpos].id);
        nodes[prepos].nextpos = nodes[nowpos].nextpos;
        nowpos = nodes[prepos].nextpos;
    }
    printf("%d", nodes[nowpos].id);
    return 0;
}
