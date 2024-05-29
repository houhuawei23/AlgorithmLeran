/*

Associative containers std::set, std::map, std::multiset, std::multimap,
std::unordered_set, std::unordered_map, std::unordered_multiset,
std::unordered_multimap are node-based data structures, and their nodes can be
extracted as an object of unspecified type known as node handle.

关联容器
std::set、std::map、std::multiset、std::multimap、std::unordered_set、
std::unordered_map、std::unordered_multiset、std::unordered_multimap
是基于节点的数据结构，它们的节点可以提取为称为节点句柄的未指定类型的对象。

Node handle is a move-only type that owns and provides access to the element
(the value_type) stored in the node, and provides non-const access to the key
part of the element (the key_type) and the mapped part of the element (the
mapped_type). If the node handle destructs while holding the node, the node is
properly destructed using the appropriate allocator for the container. The node
handle contains a copy of the container’s allocator. This is necessary so that
the node handle can outlive the container.

节点句柄是一种仅移动类型，它拥有并提供对存储在节点中的元素 (the value_type)
的访问， 并提供对元素的键部分 (the key_type ) 和元素的映射部分 (themapped_type)
的非非常量访问。
如果节点句柄在持有节点时发生破坏，则使用容器的相应分配器正确销毁节点。
节点句柄包含容器分配器的副本。这是必要的，以便节点句柄可以比容器更长久。

The exact type of node handle (shown here as  node-handle ) is unspecified, but
each container exposes its node handle type as the member node_type.

节点句柄的确切类型 (此处显示为 node-handle) 未指定，
但每个容器都将其节点句柄类型公开为成员 node_type 。

Node handles can be used to transfer ownership of an element between two
associative containers with the same key, value, and allocator type (ignoring
comparison or hash/equality), without invoking any copy/move operations on the
container element (this kind of operation is known as "splicing"). Transfer
between unique and non-unique containers is also permitted: a node handle from a
std::map can be inserted into an std::multimap, but not into std::unordered_map
or std::set.

节点句柄可用于在具有相同键、值和分配器类型的两个关联容器之间转移元素的所有权(忽略比较或哈希/相等)，
而无需对容器元素调用任何复制/移动操作(此类操作称为“拼接”)。
还允许在唯一容器和非唯一容器之间传输:std::map 中的节点句柄可以插入到
std::multimap 中， 但不能插入到 std::unordered_map 或 std::set 中。

A node handle may be empty, in which case it holds no element and no allocator.
The default-constructed and moved-from node handle is empty. In addition, an
empty node handle can be produced by a failed call to container member function
extract.

节点句柄可能为空，在这种情况下，它不包含任何元素，也不包含分配器。默认构造和移出的节点句柄为空。
此外，对容器成员函数 extract 的失败调用可能会产生一个空节点句柄。

Pointers and references to an element that are obtained while it is owned by a
node handle are invalidated if the element is successfully inserted into a
container.

如果元素成功插入到容器中，则在节点句柄拥有该元素时获取的对该元素的指针和引用将失效。

For all map containers (std::map, std::multimap, std::unordered_map, and
std::unordered_multimap) whose key_type is K and mapped_type is T, the behavior
of operations involving node handles is undefined if a user-defined
specialization of std::pair exists for std::pair<K, T> or std::pair<const K, T>.

对于 key_type 所有 is K 和 mapped_type is T 的映射容器(
std::map、std::multimap、std::unordered_map 和
std::unordered_multimap)，如果 std::pair> 存在用户定义的 std::pair
专用化，则涉及节点句柄的操作行为是未定义的。

*/