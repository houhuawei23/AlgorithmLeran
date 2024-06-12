并查集 Disjoint-set
- 每个集合用一棵树来表示, 树根的编号就是整个集合的编号
- 每个结点存储其父结点 p[x]
- 判断树根: p[x] == x
- 求x的集合编号: find(x): while(p[x] != x) x = p[x]; return x;
- 合并两个集合: p[find(x)] = find(y)
- 优化: 路径压缩, O(n) -> O(1)