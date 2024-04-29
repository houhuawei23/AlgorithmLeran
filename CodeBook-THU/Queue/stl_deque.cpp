/*
luogu P1886 滑动窗口 / [模板]单调队列

in1:
8 3
1 3 -1 -3 5 3 6 7
out1:
-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/


#include <bits/stdc++.h>

using namespace std;

#define N 1000005

int a[N];

deque<int> q;


int main(){
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++){
        while(!q.empty() && a[q.back()] > a[i]) q.pop_back();        // 去尾
        q.push_back(i);
        if(i>=k){
            while(!q.empty() && q.front() + k <= i) q.pop_front();   // 删头
            printf("%d ", a[q.front()]);
        }
    }
    printf("\n");
    q.clear();
    for (int i = 1; i <=n; i++){
        while(!q.empty() && a[q.back()] < a[i]) q.pop_back();
        q.push_back(i);
        if(i>=k){
            while(!q.empty() && q.front() + k <= i) q.pop_front();
            printf("%d ", a[q.front()]);
        }
    }
}