
常见的解决单源最短路径问题的算法包括：

- Dijkstra 算法：
  - 一种贪心算法，用于解决无负权边的情况。
  - 它逐步扩展当前已知最短路径的范围，选择当前距离起始节点最近的节点，并更新与该节点相邻的节点的距离。
  - 通过逐步选择距离起始节点最近的节点，并根据这些节点的路径更新其他节点的距离，从而逐步找到最短路径。
- Bellman-Ford 算法：
  - 适用于有负权边的情况。
  - 它通过多次迭代来逐步逼近最短路径，每次迭代都尝试通过更新边的权重来缩短路径。
- SPFA 算法：
  - 优化的 Bellman-Ford 算法
  - 在每次迭代中不遍历所有的边，而是选择性地更新与当前节点相关的边，从而提高了算法的效率。

#### Dijkstra-朴素O(n^2)

- 初始化距离数组, dist[1] = 0, dist[i] = inf;
- for n次循环 每次循环确定一个min加入S集合中，n次之后就得出所有的最短距离
- 将不在S中dist_min的点->t
- t->S加入最短路集合
- 用t更新到其他点的距离

#### Dijkstra-堆优化O(mlogm)

- 利用邻接表，优先队列
- 在 `priority_queue<PII,vector<PII>,greater<PII>> heap;` 中将返回堆顶
- 利用堆顶来更新其他点，并加入堆中类似宽搜

#### Bellman_ford O(nm)

- 注意连锁想象需要备份, struct Edge{inta,b,c} Edge[M];
- 初始化dist, 松弛dist[x.b] = min(dist[x.b], backup[x.a]+x.w);
- 松弛k次，每次访问m条边

#### Spfa O(n)~O(nm)

- 利用队列优化仅加入修改过的地方
- for k次
- for 所有边利用宽搜模型去优化bellman_ford算法
- 更新队列中当前点的所有出边

#### Floyd O(n^3)

- 初始化d
- k, i, j 去更新d

作者：郡呈
链接：https://www.acwing.com/solution/content/6976/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。