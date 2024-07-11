// CPP Code to remove an element from multiset which have
// same value
#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> a;
    a.insert(10);
    a.insert(10);
    a.insert(10);

    // it will give output 3
    cout << a.count(10) << endl;

    // removing single instance from multiset

    // it will remove only one value of
    // 10 from multiset
    a.erase(a.find(10));

    // it will give output 2
    cout << a.count(10) << endl;

    // removing all instance of element from multiset
    // it will remove all instance of value 10
    a.erase(10);

    // it will give output 0 because all
    // instance of value is removed from
    // multiset
    cout << a.count(10) << endl;

    return 0;
}
