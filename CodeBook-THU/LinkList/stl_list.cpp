/*
约瑟夫问题
stl list模拟循环链表？
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    list<int> nodes;
    for (int i = 1;i<=n;i++){nodes.push_back(i);}
    list<int>:: iterator it = nodes.begin();
    while(nodes.size() > 1){
        for(int i = 1; i<m; i++){
            it ++;
            if(it == nodes.end()) {
                it = nodes.begin();
            }
        }
        cout << *it << " ";
        list<int>::iterator next = ++it;
        if (next==nodes.end()) {
            next = nodes.begin();
        }
        nodes.erase(--it);
        it = next;
    }
    cout << *it;
    return 0;
}