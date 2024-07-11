### 并查集 Disjoint-set
- [oi-wiki](https://oi-wiki.org/ds/dsu/)
- 每个集合用一棵树来表示, 树根的编号就是整个集合的编号
- 每个结点存储其父结点 `p[x]`
- 判断树根: `p[x] == x`
- 求x的集合编号: 
  - `find(x)`: `while(p[x] != x) x = p[x]; return x;`
- 合并两个集合: `p[find(x)] = find(y)`
- 优化: 路径压缩, O(n) -> O(1)
- 拓展
  - 记录集合大小 size: 绑定到根结点
  - 记录结点到根的距离 d: 绑定到每个元素上
- 应用:
  - 连通性判断: 遍历所有边, 合并连通的点的集合, 统计共有几个集合
  - 最小生成树 Kruskal: 将所有结点分为 "入树" 和 "未入树" 两个集合
  - 最近公共祖先 LCA
- 复杂拓展
  - 可持久化并查集
  - 可撤销并查集
  [Almost Union-Find](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3138)

### 树状数组 Binary Indexed Tree
- [oi-wiki: Binary Indexed Tree](https://oi-wiki.org/ds/fenwick/)
- [wikipedia: Fenwick_tree](https://en.wikipedia.org/wiki/Fenwick_tree)
- [五分钟丝滑动画讲解 | 树状数组](https://www.bilibili.com/video/BV1ce411u7qP/)

- 单点修改, 区间查询 (基础)
- 区间修改, 单点查询: 查分数组
- 区间修改, 区间查询: 二阶树状数组
- 二维区间修改 + 区间查询
- 偏序问题(逆序对 + 离散化)
- 区间最值
- 离线处理: 读取所有查询, 统一处理, 统一输出

### 线段树 Segment Tree
- [wikipedia:Segment Tree](https://en.wikipedia.org/wiki/Segment_tree)
- [CF: SegTree](https://codeforces.com/blog/entry/57319)
- [usaco](https://usaco.guide/adv/segtree-beats?lang=cpp)
- [hackerearth](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/)
- 分治 + 二叉树 + Lazy-Tag
- 大区间的解可通过小区间的解合并而得
- 单点修改 + 区间查询 (Base) 
- 区间修改 + 区间查询 (Lazy-Tag): LuoGu P3372