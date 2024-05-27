

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    vector<Node*> children;
};

const int N = 10e5 + 5;

vector<Node*> tree(N);

int n;

void dfs(Node* root) {
    for (auto child : root->children) {
        dfs(child);
    }
    cout << root->id << " ";
}

int main() {
    cin >> n;
    /* build tree */
    for (int i = 0; i < n - 1; i++) {
        int lhs, rhs;
        cin >> lhs >> rhs;
        // cout << "in:" << lhs << " " << rhs;
        if (tree[lhs] == nullptr) {
            tree[lhs] = new Node;
            tree[lhs]->id = lhs;
        }
        if (tree[rhs] == nullptr) {
            tree[rhs] = new Node;
            tree[rhs]->id = lhs;
        }
        auto father = tree[lhs];
        auto child = tree[rhs];
        father->children.emplace_back(child);
    }
    auto root = tree[1];
    dfs(root);
}
