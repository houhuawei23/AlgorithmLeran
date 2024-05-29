/*
c++20:
- std::erase_if (std::map)
- ‘auto’ in parameter declaration:
    - void println(auto const comment, auto const& map)

(): Parentheses
[]: Brackets
{}: Braces

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class map;

std::map is a sorted associative container that contains key-value pairs with
unique keys. Keys are sorted by using the comparison function Compare. Search,
removal, and insertion operations have logarithmic complexity. Maps are usually
implemented as Red–black trees.

std::map 是一个排序的关联容器，其中包含具有唯一键的键值对。
使用比较函数 Compare 对键进行排序。搜索、删除和插入操作具有对数复杂度。
map 通常被实现为红黑树。

Iterators of std::map iterate in ascending order of keys, where ascending is
defined by the comparison that was used for construction. That is, given

m, a std::map
it_l and it_r, dereferenceable iterators to m, with it_l < it_r.

m.value_comp()(*it_l, *it_r) == true
(least to greatest if using the default comparison).

Everywhere the standard library uses the Compare requirements, uniqueness is
determined by using the equivalence relation. In imprecise terms, two objects a
and b are considered equivalent (not unique) if neither compares less than the
other: !comp(a, b) && !comp(b, a).
*/

#include <iostream>
#include <map>
#include <string>
#include <string_view>

#include <cassert>
// #include <algorithm>
// #include <vector>

void print_map(std::string_view comment, const std::map<std::string, int>& m) {
    std::cout << comment;
    // Iterate using C++17 facilities
    for (const auto& [key, value] : m)
        std::cout << '[' << key << "] = " << value << "; ";

    // C++11 alternative:
    //  for (const auto& n : m)
    //      std::cout << n.first << " = " << n.second << "; ";
    //
    // C++98 alternative:
    //  for (std::map<std::string, int>::const_iterator it = m.begin(); it !=
    //  m.end(); ++it)
    //      std::cout << it->first << " = " << it->second << "; ";

    std::cout << '\n';
}

void trySTLMap() {
    // Create a map of three (string, int) pairs
    std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};

    print_map("1) Initial map: ", m);

    m["CPU"] = 25;  // update an existing value
    m["SSD"] = 30;  // insert a new value
    print_map("2) Updated map: ", m);

    // Using operator[] with non-existent key always performs an insert
    std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
    print_map("4) Updated map: ", m);

    m.erase("GPU");
    print_map("5) After erase: ", m);

    std::erase_if(m, [](const auto& pair) { return pair.second > 25; });
    print_map("6) After erase: ", m);
    std::cout << "7) m.size() = " << m.size() << '\n';

    m.clear();
    std::cout << std::boolalpha << "8) Map is empty: " << m.empty() << '\n';
}

void println(auto const comment, auto const& map) {
    std::cout << comment << '{';
    for (const auto& pair : map)
        std::cout << '{' << pair.first << ": " << pair.second << '}';
    std::cout << "}\n";
}
/*
operator[]
*/
void trySTLMapBrackets() {
    std::map<char, int> letter_counts{{'a', 27}, {'b', 3}, {'c', 1}};

    println("letter_counts initially contains: ", letter_counts);

    letter_counts['b'] = 42;  // updates an existing value
    letter_counts['x'] = 9;   // inserts a new value

    println("after modifications it contains: ", letter_counts);

    // count the number of occurrences of each word
    // (the first call to operator[] initialized the counter with zero)
    std::map<std::string, int> word_map;
    for (const auto& w : {"this", "sentence", "is", "not", "a", "sentence",
                          "this", "sentence", "is", "a", "hoax"})
        ++word_map[w];
    word_map["that"];  // just inserts the pair {"that", 0}

    for (const auto& [word, count] : word_map)
        std::cout << count << " occurrence(s) of word '" << word << "'\n";
}

void trySTLMapInsert() {
    std::map<int, std::string> mapStu;

    // 第一种 通过pair的方式插入对象
    mapStu.insert(std::pair<int, std::string>(3, "小张"));

    // 第二种
    // 通过make_pair的方式插入对象
    mapStu.insert(std::make_pair(-1, "校长"));

    // 第三种 通过value_type的方式插入对象
    mapStu.insert(std::map<int, std::string>::value_type(1, "小李"));

    // 第四种 通过数组的方式插入值
    // 这种方式在键已存在时更新对应的值，在键不存在时插入新的键值对
    mapStu[3] = "小刘";  // 注意：这会替换掉key为3的原始值"小张"
    mapStu[5] = "小王";

    // 输出map内容
    for (const auto& kv : mapStu) {
        std::cout << kv.first << ": " << kv.second << std::endl;
    }
}
/*
1 iterator erase( iterator pos );
2 iterator erase( const_iterator pos );	                        (since C++11)
3 iterator erase( iterator first, iterator last );              (until C++11)
3 iterator erase( const_iterator first, const_iterator last );  (since C++11)
    - return Iterator following the last removed element.
4 size_type erase( const Key& key );
    - return The number of elements removed (0 or 1)
5 template< class K > size_type erase( K&& x );                 (since C++23)
    - return The number of elements removed.

1,2) Removes the element at pos.
3) Removes the elements in the range [first, last), which must be a valid range
in *this.
4) Removes the element (if one exists) with the key equivalent to key.
5) Removes all elements with key that compares equivalent to the value x. This
overload participates in overload resolution only if the qualified-id
Compare::is_transparent is valid and denotes a type, and neither iterator nor
const_iterator is implicitly convertible from K. It allows calling this function
without constructing an instance of Key.

Complexity:
1,2) Amortized constant
3) log(c.size()) + std::distance(first, last)
4) log(c.size()) + c.count(key)
5) log(c.size()) + c.count(x)

*/
void trySTLMapErase() {
    std::map<int, std::string> c = {{1, "one"},  {2, "two"},  {3, "three"},
                                    {4, "four"}, {5, "five"}, {6, "six"}};

    // erase all odd numbers from c
    for (auto it = c.begin(); it != c.end();) {
        if (it->first % 2 != 0)
            it = c.erase(it);
        else
            ++it;
    }

    for (auto& p : c)
        std::cout << p.second << ' ';
    std::cout << '\n';

    // 1. iterator erase(iterator pos);
    {
        std::map<int, char> m = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
        auto it = m.find(2);
        it = m.erase(it);
        assert(m.size() == 2);
        assert(m.find(2) == m.end());
        assert(it == m.find(3));
    }

    // 2. iterator erase(const_iterator pos);
    {
        std::map<int, char> m = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
        std::map<int, char>::const_iterator it = m.find(2);
        it = m.erase(it);
        assert(m.size() == 2);
        assert(m.find(2) == m.end());
        assert(it == m.find(3));
    }

    // 3. iterator erase(iterator first, iterator last); (until C++11)
    // 3. iterator erase(const_iterator first, const_iterator last); (since
    // C++11)
    {
        std::map<int, char> m = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}};
        auto it1 = m.find(2);
        auto it2 = m.find(4);
        auto it = m.erase(it1, it2);
        assert(m.size() == 2);
        assert(m.find(2) == m.end());
        assert(m.find(3) == m.end());
        assert(it == m.find(4));
    }

    // 4. size_type erase(const Key& key);
    {
        std::map<int, char> m = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
        size_t count = m.erase(2);
        assert(count == 1);
        assert(m.size() == 2);
        assert(m.find(2) == m.end());
    }

    // 5. template<class K> size_type erase(K&& x); (since C++23)
    {
        std::map<int, char> m = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
        size_t count = m.erase(2);
        assert(count == 1);
        assert(m.size() == 2);
        assert(m.find(2) == m.end());

        // Ensure it works with different types
        std::map<std::string, int> sm = {{"one", 1}, {"two", 2}, {"three", 3}};
        std::string key = "two";
        count = sm.erase(key);
        assert(count == 1);
        assert(sm.size() == 2);
        assert(sm.find("two") == sm.end());
    }

    std::cout << "All test cases passed!" << std::endl;
}

/*
std::pair<iterator, bool> insert( const value_type& value ); (1)

template< class P >
std::pair<iterator, bool> insert( P&& value ); (2)  (since C++11)

std::pair<iterator, bool> insert( value_type&& value ); (3)  (since C++17)

iterator insert( iterator pos, const value_type& value ); (4) (until C++11)
iterator insert( const_iterator pos, const value_type& value ); (4) (since
C++11)

template< class P >
iterator insert( const_iterator pos, P&& value ); (5)  (since C++11)

iterator insert( const_iterator pos, value_type&& value ); (6)  (since C++17)

template< class InputIt >
void insert( InputIt first, InputIt last ); (7)

void insert( std::initializer_list<value_type> ilist ); (8)  (since C++11)

insert_return_type insert( node_type&& nh ); (9)  (since C++17)

iterator insert( const_iterator pos, node_type&& nh ); (10)  (since C++17)

Explanation:

pos	-	iterator to the position before which the new element will be inserted
value	-	element value to insert
first, last	-	range of elements to insert
ilist	-	initializer list to insert the values from
nh	-	a compatible node handle

Inserts element(s) into the container, if the container doesn't already contain
an element with an equivalent key.

1-3) Inserts value.
 Overload (2) is equivalent to emplace(std::forward<P>(value)) and only
participates in overload resolution if
std::is_constructible<value_type, P&&>::value == true.

4-6) Inserts value in the position as close as possible to the position just
prior to pos. Overload (5) is equivalent to emplace_hint(hint,
std::forward<P>(value)) and only participates in overload resolution if
std::is_constructible<value_type, P&&>::value == true.

7) Inserts elements from range [first, last). If multiple elements in the range
have keys that compare equivalent, it is unspecified which element is inserted
(pending LWG2844).

8) Inserts elements from initializer list ilist. If multiple elements in the
range have keys that compare equivalent, it is unspecified which element is
inserted (pending LWG2844).

9) If nh is an empty node handle, does nothing. Otherwise, inserts the element
owned by nh into the container , if the container doesn't already contain an
element with a key equivalent to nh.key(). The behavior is undefined if nh is
not empty and get_allocator() != nh.get_allocator().

10) If nh is an empty node handle, does nothing and returns the end iterator.
Otherwise, inserts the element owned by nh into the container, if the container
doesn't already contain an element with a key equivalent to nh.key(), and
returns the iterator pointing to the element with key equivalent to
nh.key()(regardless of whether the insert succeeded or failed). If the insertion
succeeds, nh is moved from, otherwise it retains ownership of the element. The
element is inserted as close as possible to the position just prior to pos. The
behavior is undefined if nh is not empty and get_allocator() !=
nh.get_allocator().

No iterators or references are invalidated. If the insertion is successful,
pointers and references to the element obtained while it is held in the node
handle are invalidated, and pointers and references obtained to that element
before it was extracted become valid.(since C++17)

Return value:

1-3) A pair consisting of an iterator to the inserted element (or to the element
that prevented the insertion) and a bool value set to true if and only if the
insertion took place.

4-6) An iterator to the inserted element, or to the element that prevented the
insertion.

7,8) (none)

9) An object of insert_return_type with the members initialized as follows:
If nh is empty, inserted is false, position is end(), and node is empty.
Otherwise if the insertion took place, inserted is true, position points to the
inserted element, and node is empty. If the insertion failed, inserted is false,
node has the previous value of nh, and position points to an element with a key
equivalent to nh.key().

10) End iterator if nh was empty, iterator pointing to the inserted element if
insertion took place, and iterator pointing to an element with a key equivalent
to nh.key() if it failed.

Complexity
1-3) Logarithmic in the size of the container, O(log(size())).

4-6) Amortized constant if the insertion happens in the position just
after(until C++11)before(since C++11) pos, logarithmic in the size of the
container otherwise.

7,8) O(N·log(size() + N)), where N is the number of elements to insert.

9) Logarithmic in the size of the container, O(log(size())).

10) Amortized constant if the insertion happens in the position just before pos,
logarithmic in the size of the container otherwise.
*/
#include <iomanip>
using namespace std::literals;

template <typename It>
void print_insertion_status(It it, bool success) {
    std::cout << "Insertion of " << it->first
              << (success ? " succeeded\n" : " failed\n");
}
void trySTLMapInsert2() {
    std::map<std::string, float> heights;

    // Overload 3: insert from rvalue reference
    const auto [it_hinata, success] = heights.insert({"Hinata"s, 162.8});
    print_insertion_status(it_hinata, success);

    {
        // Overload 1: insert from lvalue reference
        const auto [it, success2] = heights.insert(*it_hinata);
        print_insertion_status(it, success2);
    }
    {
        // Overload 2: insert via forwarding to emplace
        const auto [it, success] = heights.insert(std::pair{"Kageyama", 180.6});
        print_insertion_status(it, success);
    }
    {
        // Overload 6: insert from rvalue reference with positional hint
        const std::size_t n = std::size(heights);
        const auto it = heights.insert(it_hinata, {"Azumane"s, 184.7});
        print_insertion_status(it, std::size(heights) != n);
    }
    {
        // Overload 4: insert from lvalue reference with positional hint
        const std::size_t n = std::size(heights);
        const auto it = heights.insert(it_hinata, *it_hinata);
        print_insertion_status(it, std::size(heights) != n);
    }
    {
        // Overload 5: insert via forwarding to emplace with positional hint
        const std::size_t n = std::size(heights);
        const auto it =
            heights.insert(it_hinata, std::pair{"Tsukishima", 188.3});
        print_insertion_status(it, std::size(heights) != n);
    }

    auto node_hinata = heights.extract(it_hinata);
    std::map<std::string, float> heights2;

    // Overload 7: insert from iterator range
    heights2.insert(std::begin(heights), std::end(heights));

    // Overload 8: insert from initializer_list
    heights2.insert({{"Kozume"s, 169.2}, {"Kuroo", 187.7}});

    // Overload 9: insert node
    const auto status = heights2.insert(std::move(node_hinata));
    print_insertion_status(status.position, status.inserted);

    node_hinata = heights2.extract(status.position);
    {
        // Overload 10: insert node with positional hint
        const std::size_t n = std::size(heights2);
        const auto it =
            heights2.insert(std::begin(heights2), std::move(node_hinata));
        print_insertion_status(it, std::size(heights2) != n);
    }

    // Print resulting map
    std::cout << std::left << '\n';
    for (const auto& [name, height] : heights2)
        std::cout << std::setw(10) << name << " | " << height << "cm\n";
}
/*
template< class... Args >
std::pair<iterator, bool> emplace( Args&&... args ); (since C++11)

Inserts a new element into the container constructed in-place with the given
args, if there is no element with the key in the container.

The constructor of the new element (i.e. std::pair<const Key, T>) is called with
exactly the same arguments as supplied to emplace, forwarded via
std::forward<Args>(args).... The element may be constructed even if there
already is an element with the key in the container, in which case the newly
constructed element will be destroyed immediately.

Careful use of emplace allows the new element to be constructed while avoiding
unnecessary copy or move operations.

No iterators or references are invalidated.

Return value 返回值

A pair consisting of an iterator to the inserted element (or to the element that
prevented the insertion) and a bool value set to true if and only if the
insertion took place.

一对，由插入元素 (或阻止插入的元素) 的迭代器和设置为 true 的布尔值组成，
当且仅当插入发生时。

Complexity 复杂性
Logarithmic in the size of the container.
*/
void trySLTMapEmplace() {
    std::map<std::string, std::string> m;

    // uses pair's move constructor
    m.emplace(std::make_pair(std::string("a"), std::string("a")));

    // uses pair's converting move constructor
    m.emplace(std::make_pair("b", "abcd"));

    // uses pair's template constructor
    m.emplace("d", "ddd");

    // emplace with duplicate key has no effect
    m.emplace("d", "DDD");

    // uses pair's piecewise constructor
    m.emplace(std::piecewise_construct, std::forward_as_tuple("c"),
              std::forward_as_tuple(10, 'c'));
    // an alternative is: m.try_emplace("c", 10, 'c');

    for (const auto& p : m)
        std::cout << p.first << " => " << p.second << '\n';
}

void print(std::string_view comment, const auto& data) {
    std::cout << comment;
    for (auto [k, v] : data)
        std::cout << ' ' << k << '(' << v << ')';

    std::cout << '\n';
}

/*
node_type extract( const_iterator position ); (1)	(since C++17)

node_type extract( const Key& k ); (2)	(since C++17)

template< class K >
node_type extract( K&& x ); (3)	(since C++23)

1) Unlinks the node that contains the element pointed to by position and returns
a node handle that owns it.

1)  取消链接包含按位置指向的元素的节点，并返回拥有该元素的节点句柄。

2) If the container has an element with key equivalent to k, unlinks the node
that contains that element from the container and returns a node handle that
owns it. Otherwise, returns an empty node handle.

2)  如果容器具有键等于 k
的元素，则从容器中取消包含该元素的节点的链接，并返回拥有该元素的节点句柄。否则，返回一个空节点句柄。

3) Same as (2). This overload participates in overload resolution only if the
qualified-id Compare::is_transparent is valid and denotes a type, and neither
iterator nor const_iterator is implicitly convertible from K. It allows calling
this function without constructing an instance of Key.

3) 与 (2) 相同。仅当 qualified-id Compare：：is_transparent
有效且表示类型，并且既不能 iterator const_iterator 也不能隐式地从 转换时 K
，此重载才会参与重载解析。它允许调用此函数，而无需构造 Key 的实例。

In either case, no elements are copied or moved, only the internal pointers of
the container nodes are repointed (rebalancing may occur, as with erase()).

无论哪种情况，都不会复制或移动任何元素，只会重新指向容器节点的内部指针
(可能会发生重新平衡，就像 erase ()  一样) 。

Extracting a node invalidates only the iterators to the extracted element.
Pointers and references to the extracted element remain valid, but cannot be
used while element is owned by a node handle: they become usable if the element
is inserted into a container.

提取节点只会使提取的元素的迭代器失效。对提取的元素的指针和引用仍然有效，但在元素归节点句柄所有时不能使用：如果元素插入到容器中，则它们变得可用。

Parameters
position	-	a valid iterator into this container
k	-	a key to identify the node to be extracted
x	-	a value of any type that can be transparently compared with a key
identifying the node to be extracted

Return value
A node handle that owns the extracted element, or empty node handle in case the
element is not found in (2,3).

*/
void trySTLMapExtract() {
    std::map<int, char> cont{{1, 'a'}, {2, 'b'}, {3, 'c'}};

    print("Start:", cont);

    // Extract node handle and change key
    auto nh = cont.extract(1); /* Node handle (c++17)*/
    nh.key() = 4;

    std::cout << "nh.key() = " << nh.key() << '\n';

    print("After extract and before insert:", cont);

    // Insert node handle back
    cont.insert(std::move(nh));

    print("End:", cont);
}
/*
template< class C2 >
void merge( std::map<Key, T, C2, Allocator>& source );

Attempts to extract ("splice") each element in source and insert it into *this
using the comparison object of *this. If there is an element in *this with key
equivalent to the key of an element from source, then that element is not
extracted from source. No elements are copied or moved, only the internal
pointers of the container nodes are repointed. All pointers and references to
the transferred elements remain valid, but now refer into *this, not into
source.

尝试提取 (“拼接”) 源中的每个元素并使用 *this 的比较对象将其插入到 *this 中。
如果 *this 中有一个元素的键等于源中某个元素的键，则不会从源中提取该元素。
不复制或移动任何元素，仅重新指向容器节点的内部指针。
对传输元素的所有指针和引用仍然有效，但现在引用 *this，而不是源。

The behavior is undefined if get_allocator() != source.get_allocator().
如果 get_allocator() != source.get_allocator() 则行为未定义。

Parameters
source	-	compatible container to transfer the nodes from
Return value
(none)

Exceptions
Does not throw unless comparison throws.

Complexity
N * log(size() + N)), where N is source.size().
*/
void trySTLMapMerge() {
    std::map<int, std::string> ma{{1, "apple"}, {5, "pear"}, {10, "banana"}};
    std::map<int, std::string> mb{
        {2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};

    std::map<int, std::string> u;

    u.merge(ma);
    std::cout << "ma.size(): " << ma.size() << '\n';
    std::cout << "u.size(): " << u.size() << '\n';

    u.merge(mb);
    std::cout << "mb.size(): " << mb.size() << '\n';
    std::cout << "u.size(): " << u.size() << '\n';

    std::cout << "mb.at(5): " << mb.at(5) << '\n';

    for (auto const& kv : u)
        std::cout << kv.first << ", " << kv.second << '\n';
}
/* default Ascending order: small -> large */
/* using std:greater, large -> small */
void trySTLMapDescending() {
    std::map<int, std::string, std::greater<int>> mapStuDesc;

    mapStuDesc[3] = "小张";
    mapStuDesc[5] = "小王";
    mapStuDesc[1] = "小李";

    // 遍历map并输出元素
    for (const auto& pair : mapStuDesc) {
        std::cout << "键: " << pair.first << ", 值: " << pair.second
                  << std::endl;
    }
}
struct MyCompare {
    bool operator()(const int& a, const int& b) const {
        // 在这里实现你的比较逻辑
        // 例如，假设我们想要按照键的绝对值来排序
        return std::abs(a) < std::abs(b);
    }
};

void trySTLMapCustomCompare() {
    std::map<int, std::string, MyCompare> mapAbsDesc;

    mapAbsDesc[-3] = "小张";
    mapAbsDesc[5] = "小王";
    mapAbsDesc[-1] = "小李";

    // 遍历map并输出元素
    for (const auto& pair : mapAbsDesc) {
        std::cout << "键: " << pair.first << ", 值: " << pair.second
                  << std::endl;
    }
}

int main() {
    // trySTLMap();
    // trySTLMapBrackets();
    // trySTLMapInsert();
    // trySTLMapErase();
    // trySTLMapInsert2();
    // trySLTMapEmplace();
    // trySTLMapExtract();
    // trySTLMapMerge();
    // trySTLMapDescending();
    trySTLMapCustomCompare();
    return 0;
}