#include <bits/stdc++.h>

using namespace std;


struct node {
    int data;
    node* next;
};

int main(){
    int n,m; 
    scanf("%d %d", &n, &m);
    node * head, * now, * p, * prev;
    head = new node; head->data = 1; head->next = NULL;
    now = head;
    for (int i = 2; i<=n; i++){
        p = new node; p->data = i; p->next = NULL;
        now->next = p; now = p;
    }
    now->next = head;

    // 模拟出圈
    now = head;
    prev = head;
    while((n--)>1){ // for all to 1, special for 1
        for (int i=1; i<m; i++){//数数
            prev = now; // 记录上一个节点
            now = now->next;
        }
        printf("%d ", now->data);
        // printf("delete: %d\n", now->data);
        // printf("- prev: %d\n", prev->data);
        prev->next = now->next;
        // printf("now->data: %d\n", now->data);
        // printf("- prev: %d\n", prev->data);
        delete now;
        // printf("now->data: %d\n", now->data);
        // printf("- prev->data: %d\n", prev->data);
        // if (now == NULL){
        //     printf("now is NULL\n");
        // }
        now = prev->next;
    }
    printf("%d", now->data);
    delete now;
    return 0;
}