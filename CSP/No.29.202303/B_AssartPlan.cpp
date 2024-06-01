/*
70/100
m 1e9: time out
*/

#include <bits/stdc++.h>

using namespace std;

// priority_queue<int, vector<int>, less<int>> q;

struct Node {
    int t;
    int c;
    Node() : t(0), c(0) {}
    Node(int ti, int ci) : t(ti), c(ci) {}
    bool operator<(const Node& other) const {
        if (t != other.t) {
            return t < other.t;
        }
        return c > other.c;
    }
    void print(std::ostream& out = std::cout) const {
        out << "t: " << t << ", " << "c: " << c << endl;
    }
};

priority_queue<Node> pq;

void print_pq(priority_queue<Node> pq) {
    while (not pq.empty()) {
        pq.top().print();
        pq.pop();
    }
}
int n, m, k;

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int t, c;
        cin >> t >> c;
        pq.push(Node(t, c));
    }
    // print_pq(pq);
    // print_pq(pq);
    Node top;
    while (true) {
        top = pq.top();
        pq.pop();
        if (m < top.c or top.t <= k) {
            pq.push(top);
            break;
        }
        // invest resources
        m -= top.c;
        top.t -= 1;
        pq.push(top);
    }
    // print_pq(pq);
    top = pq.top();
    int minMaxDay;
    if (top.t < k) {
        minMaxDay = k;
    } else {
        minMaxDay = top.t;
    }
    cout << minMaxDay;
}