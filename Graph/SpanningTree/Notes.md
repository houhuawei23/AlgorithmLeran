**Kruskal 的 MST 算法**

给定一个连通无向图，该图的生成树是一个子图，它是一棵树，将所有顶点连接在一起。一个图可以有许多不同的生成树。加权、连通和无向图的最小生成树 (MST) 或最小权重生成树是权重小于或等于所有其他生成树的权重的生成树。生成树的权重是赋予生成树的每条边的权重之和。

以下是使用 Kruskal 算法查找 MST 的步骤：

- 按权重的非递减顺序对所有边进行排序。
- 选择最小的边。检查它是否与到目前为止形成的生成树形成一个循环。如果没有形成循环，则包括该边。否则，丢弃它。
- 重复步骤#2，直到生成树中有 (V-1) 条边。

**Prim 的 MST 算法**

与 Kruskal 算法一样，Prim 算法也是一种贪心算法。它从一棵空的生成树开始。这个想法是保持两组顶点。第一个集合包含已包含在 MST 中的顶点，另一个集合包含尚未包含的顶点。在每一步，它都会考虑连接这两个集合的所有边，并从这些边中选择最小权重边。拾取边缘后，它将边缘的另一个端点移动到包含 MST 的集合。

**以下是使用 Prim 算法查找 MST 的步骤**

- 创建一个集合 mstSet 来跟踪已包含在 MST 中的顶点。
- 为输入图中的所有顶点分配一个键值。将所有键值初始化为 INFINITE。将第一个顶点的键值指定为 0，以便首先拾取它。
- 当 mstSet 不包括所有顶点：
    - 选择一个在 mstSet 中不存在且具有最小键值的顶点 u。
    - 将 u 包含到 mstSet。
    - 更新 u 的所有相邻顶点的键值。要更新键值，请遍历所有相邻顶点。对于每一个相邻的顶点v，如果边u-v的权重小于v的前一个key值，则更新key值作为u-v的权重

Prim 和 Kruskal 的算法都找到最小生成树并遵循解决问题的贪婪方法，但它们之间几乎没有主要区别。

| Prim算法                                                                                | Kruskal算法                                                             |
| --------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| Prim算法开始从图中的任何顶点构建最小生成树。                                            | Kruskal算法从图中权重最小的顶点开始构建最小生成树。                     |
| Prim算法遍历一个节点不止一次以获得最小距离。                                            | Kruskal算法只遍历一个节点一次。                                         |
| Prim算法的时间复杂度为 O(V2)，V 是顶点的数量，并且可以使用斐波那契堆提高到 O(E log V)。 | Kruskal算法的时间复杂度为 O(E log V)，V 为顶点数。                      |
| Prim的算法给出了连通分量，并且它只适用于连通图。                                        | Kruskal算法可以在任何时刻生成森林(断开的组件)，也可以在断开的组件上工作 |
| Prim的算法在密集图中运行得更快。                                                        | Kruskal算法在稀疏图中运行得更快。                                       |
| Prim算法从根顶点开始生成最小生成树。                                                    | Kruskal算法从权重最小的边开始生成最小生成树。                           |
| prim算法的应用是旅行商问题、连接所有城市的公路和铁路网络等。                            | Kruskal算法的应用是 LAN 连接、电视网络等。                              |
