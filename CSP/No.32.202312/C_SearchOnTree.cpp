/*
树上搜索

Sim 60/100 time out, need optimization

样例1输入
5 2
10 50 10 10 20
1 1 3 3
5
3
样例1输出
2 5
2 5 3 4
*/
/*
build the tree
calcualte w_delta for all nodes
choose the min w_delta (node n) and query
if yes:
    keep n and its followings
else:
    remove n and its followings
if only one node, over
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2010;
const int MAXM = 110;

bool debug = false;

int n, m;

int c[MAXM];

struct Node {
    int parent;
    int w;
    unordered_set<int> children;
};
// nodes[MAXN];

vector<Node> nodes(MAXN);

void print_tree(const vector<Node>& tree) {
    for (int i = 1; i <= n; i++) {
        cout << "node: " << i << ", w: " << tree[i].w << endl;
        cout << "children: ";
        for (auto child : tree[i].children) {
            cout << child << " ";
        }
        cout << endl;
    }
}
/* dfs */
void sum_tree(const int rootid,
              const vector<Node>& tree,
              unordered_map<int, int>& sums) {
    assert(rootid < tree.size());
    const auto& root = tree[rootid];
    int sum = root.w;
    for (auto child : root.children) {
        sum_tree(child, tree, sums);
        assert(sums.find(child) != sums.cend());
        sum += sums[child];
    }
    sums[rootid] = sum;
}

// int sum_tree_beta(const int rootid,
//                   const vector<Node>& tree,
//                   unordered_map<int, int>& sums) {

//                   }

bool isFollowedBy(const vector<Node>& tree, const int rootid, const int id) {
    if (rootid == id) {
        return true;
    }
    const auto& children = tree[rootid].children;
    auto iter = children.find(id);
    if (iter != children.cend()) {
        return true;
    }
    for (auto child : children) {
        if (isFollowedBy(tree, child, id)) {
            return true;
        }
    }
    return false;
};

void solve(vector<Node> tree, const int cls) {
    if (debug) {
        cout << "solve: " << cls << endl;
    }
    int rootid = 1;
    /* id -> sum */
    unordered_map<int, int> sums;
    auto print_sums = [](const unordered_map<int, int>& sums) {
        for (const auto& pair : sums) {
            cout << "id: " << pair.first << ", sum: " << pair.second << endl;
        }
    };
    // sum_tree(rootid, tree, sums);

    auto select = [](const unordered_map<int, int>& sums, int rootid) {
        int minW_idx = rootid;
        for (const auto& pair : sums) {
            auto id = pair.first;
            auto sum = pair.second;
            auto rootsum = sums.at(rootid);

            auto min_w = abs(rootsum - 2 * sums.at(minW_idx));
            auto cur_w = abs(rootsum - 2 * sum);

            if (cur_w < min_w) {
                minW_idx = id;
            } else if (cur_w == min_w) {
                minW_idx = min(minW_idx, id);
            }
        }
        return minW_idx;
    };
    vector<int> querys;
    while (not tree[rootid].children.empty()) { /* log n */
        /* for each query */
        sums.clear();
        sum_tree(rootid, tree, sums);        /* dfs n ? */
        int minW_idx = select(sums, rootid); /* n */
        querys.push_back(minW_idx);

        if (debug) {
            cout << "rootid: " << rootid << ", ";
            cout << "minW_idx: " << minW_idx << endl;
            print_sums(sums);
        }
        /* if correct, else .. */
        if (isFollowedBy(tree, minW_idx, cls)) { /* n */
            /* keep minW_idx and its followings */
            rootid = minW_idx;
            if (debug) {
                cout << "yes" << endl;
            }
        } else {
            /* remove minW_idx and its followings */
            auto pid = tree[minW_idx].parent;
            // assert(tree[pid].children.find(minW_idx) !=
            //        tree[pid].children.cend());
            tree[pid].children.erase(minW_idx);

            if (debug) {
                cout << "no" << endl;
            }
        }
    }

    // cout << "querys: ";
    for (auto q : querys) {
        cout << q << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].w;
    }
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        nodes[i].parent = p;
        nodes[p].children.insert(i);
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    if (debug)
        print_tree(nodes);

    for (int i = 1; i <= m; i++) {
        solve(nodes, c[i]);
    }
}

/*
input:
10 3
10 2 5 10 10 1 1 10 1 8
1 1 3 1 1 5 3 2 6
8
6
4
output:
3 4 8
3 5 6 10
3 4

*/