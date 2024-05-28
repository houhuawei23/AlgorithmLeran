/*
4 30 2
6 1
5 1
6 2
7 1

*/

#include <bits/stdc++.h>

using namespace std;

int n, m, k;

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

    size_t hash() const { return std::hash<int>{}(t); }
};

struct NodeHasher final {
    size_t operator()(const Node& node) const { return node.hash(); }
};

// priority_queue<Node> pq;
// unordered_set<Node, NodeHasher> nodeSet;
// unordered_map<int, Node> bigArea;
map<int, Node, greater<int>> bigArea; /* t -> node, descend */

void print_bigArea(std::ostream& out = std::cout) {
    out << "bigArea: " << endl;
    for (auto pair : bigArea) {
        auto& node = pair.second;
        node.print();
    }
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int t, c;
        cin >> t >> c;
        if (auto iter = bigArea.find(t); iter != bigArea.cend()) {
            // found
            Node& area = (*iter).second;
            area.c += c;
        } else {
            bigArea[t] = Node(t, c);
        }
    }
    // print_bigArea();
    Node top;
    while (true) {
        // print_bigArea();

        auto iter = bigArea.begin();
        auto top = (*iter).second; /* copy construct */
        if (top.c > m or top.t <= k) {
            break;
        }
        /* invest */
        bigArea.erase(top.t);  // pop
        m -= top.c;
        top.t -= 1;
        if (auto iter = bigArea.find(top.t); iter != bigArea.cend()) {
            /* found */
            Node& area = (*iter).second;
            area.c += top.c;
        } else {
            bigArea[top.t] = top;
        }
    }
    // print_bigArea();

    // cout << "top: " << endl;
    auto iter = bigArea.begin();
    top = (*iter).second;
    // top.print();
    cout << top.t;
}