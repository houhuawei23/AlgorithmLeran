/*
约瑟夫问题
stl list模拟循环链表?

迭代器操作 iterator it:
    next(it), prev(it)
    distance(it1, it2)
    advance(it, 2)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    list<int> nodes;
    for (int i = 1; i <= n; i++) {
        nodes.push_back(i);
    }
    list<int>::iterator it = nodes.begin();
    while (nodes.size() > 1) {
        for (int i = 1; i < m; i++) {
            it++;
            if (it == nodes.end()) {
                it = nodes.begin();
            }
        }
        cout << *it << " ";
        list<int>::iterator nextit = next(it);

        if (nextit == nodes.end()) {
            nextit = nodes.begin();
        }
        nodes.erase(it);
        it = nextit;
    }
    cout << *it;
    return 0;
}
/*

#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> v{3, 1, 4};

    auto it = v.end();
    auto pv = std::prev(it, 2);
    std::cout << *pv << '\n'; // 2

    it = v.begin();
    pv = std::prev(it, -2);
    std::cout << *pv << '\n'; // 4
}

1
4
*/