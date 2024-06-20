/*
THU CS 2024 Summer Camp Computer-Based Test. B
Max-Min Search + alpha-beta pruning
only simulate the max-min search(down to top), TLE(45/100).

input:
n k a
op x w [x n]

n: numb of operations
k: max depth of the search tree
a: init value of root (with curIdx = 1)
op:
    case 1:
        insert new node under node[x], with init value w
        if(node[x] not exists) err
        if(node[x].depth >= k) err
    case 2:
        update value of node[x] with w
        if(node[x] not exists) err
        if(node[x] not leaf) err
    print root.value after each operation.

test case:
input:
10 2 1
2 1 2
1 1 3
1 2 2
1 3 1
1 2 1
2 2 4
2 4 3
1 1 5
2 6 1
2 5 1
output:
2
3
2
ERR
1
ERR
2
5
ERR
2
https://oi-wiki.org/search/alpha-beta/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;

int cnt;
int n, k;

struct Node {
    /* if leaf, value of its own;
    ** else, value of max-min search result */
    int idx;
    int value;
    int depth;
    vector<int> children;

    bool isLeaf() { return children.empty(); }
    int searchMaxMin();
    int maxValue();
    int minValue();

    int searchAlphaBeta();
    int maxValueAlpha(int alpha, int beta);
    int minValueBeta(int alpha, int beta);

} tree[N];

int Node::searchMaxMin() { return maxValue(); }
int Node::maxValue() {
    if(isLeaf()) { return value; }
    int curVal = -INF;
    for(auto idx : children) {
        auto& child = tree[idx];
        int val = child.minValue();
        if(val > curVal) { curVal = val; }
    }
    return curVal;
}
int Node::minValue() {
    if(isLeaf()) { return value; }
    int curVal = INF;
    for(auto idx : children) {
        auto& child = tree[idx];
        int val = child.maxValue();
        if(val < curVal) { curVal = val; }
    }
    return curVal;
}

int Node::searchAlphaBeta() { return maxValueAlpha(-INF, INF); }
/* father - this - child */
int Node::maxValueAlpha(int alpha, int beta) {
    /* inherit alpha beta of father, and update alpha, pass to child */
    if(isLeaf()) return value;
    int maxVal = -INF;
    for(auto idx : children) {
        auto& child = tree[idx];
        int val = child.minValueBeta(alpha, beta);
        /* searched val > maxVal, update maxVal and alpha
        ** alpha: best maxVal has been searched */
        if(val > maxVal) {
            maxVal = val;
            alpha = max(alpha, maxVal);
        }
        /* best minVal of father <= maxVal of current node,
        ** so father(min) will not choose this node as best choice,
        ** dont need to search children of this node any more, just break. */
        if(beta <= maxVal) break;
    }
    return maxVal;
}
int Node::minValueBeta(int alpha, int beta) {
    /* inherit alpha beta from father */
    if(isLeaf()) return value;
    int minVal = INF;
    for(auto idx : children) {
        auto& child = tree[idx];
        int val = child.maxValueAlpha(alpha, beta);
        /* searched val < minVal, update minVal and beta
        ** beta: best minVal has been searched */
        if(val < minVal) {
            minVal = val;
            beta = min(beta, minVal);
        }
        /* search on all children to current child,
        ** current minVal already <= alpha,
        ** the remaining child can only decrease minVal
        ** but father already has better choice with value alpha,
        ** so this node do not need to search the remaing children,
        ** so prune them. */
        if(minVal <= alpha) break;
    }
    return minVal;
}
auto& root = tree[1];

bool sim(const int op, const int x, const int w) {
    /* if(node[x] not exists) err */
    if(x > cnt) return false;
    auto& nodex = tree[x];
    auto insertNewNode = [&](const int x, const int w) {
        /* if(node[x].depth >= k) err */
        if(nodex.depth >= k) return false;
        cnt++;
        auto& child = tree[cnt];
        child.idx = cnt;
        child.value = w;
        child.depth = nodex.depth + 1;
        nodex.children.push_back(cnt);
        return true;
    };
    auto updateValue = [&](const int x, const int w) {
        /* if(node[x] not leaf) err */
        if(not nodex.isLeaf()) return false;
        nodex.value = w;
        return true;
    };
    switch(op) {
        case 1:
            /* 1 x w: insert new node(w) after node[x] */
            if(not insertNewNode(x, w)) return false;
            break;
        case 2:
            /* 2 x w: update value of node[x] with w*/
            if(not updateValue(x, w)) return false;
            break;
        default:
            return false;
            break;
    }
    // int rootVal = root.searchMaxMin();
    auto rootVal = root.searchAlphaBeta();
    cout << rootVal << endl;
    return true;
}

int main() {
    int a;
    cin >> n >> k >> a;
    cnt++;
    root.idx = 1;
    root.value = a;
    while(n--) {
        int op, x, w;
        cin >> op >> x >> w;
        if(not sim(op, x, w)) { cout << "ERR" << endl; }
    }
    return 0;
}