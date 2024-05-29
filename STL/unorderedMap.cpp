/*
template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class unordered_map;

std::unordered_map 是一个关联容器，其中包含具有唯一键的键值对。
元素的搜索、插入和删除具有平均恒定时间复杂度。

std::unordered_map is an associative container that contains key-value pairs
with unique keys. Search, insertion, and removal of elements have average
constant-time complexity.

在内部，元素不按任何特定顺序排序，而是组织到存储桶中。
元素被放入哪个桶中完全取决于其键的哈希值。具有相同哈希码的键出现在同一个桶中。
这允许快速访问单个元素，因为一旦计算出哈希值，它就会引用该元素放入的确切存储桶。

Internally, the elements are not sorted in any particular order, but organized
into buckets. Which bucket an element is placed into depends entirely on the
hash of its key. Keys with the same hash code appear in the same bucket. This
allows fast access to individual elements, since once the hash is computed, it
refers to the exact bucket the element is placed into.

Two keys are considered equivalent if the map's key equality predicate returns
true when passed those keys. If two keys are equivalent, the hash function must
return the same value for both keys.

std::unordered_map meets the requirements of Container, AllocatorAwareContainer,
UnorderedAssociativeContainer.


*/

#include <iostream>
#include <string>
#include <unordered_map>

void unorderedMap() {
    // Create an unordered_map of three strings (that map to strings)
    std::unordered_map<std::string, std::string> u = {
        {"RED", "#FF0000"}, {"GREEN", "#00FF00"}, {"BLUE", "#0000FF"}};

    // Helper lambda function to print key-value pairs
    auto print_key_value = [](const auto& key, const auto& value) {
        std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
    };

    std::cout << "Iterate and print key-value pairs of unordered_map, being\n"
                 "explicit with their types:\n";
    for (const std::pair<const std::string, std::string>& n : u)
        print_key_value(n.first, n.second);

    std::cout << "\nIterate and print key-value pairs using C++17 structured "
                 "binding:\n";
    for (const auto& [key, value] : u)
        print_key_value(key, value);

    // Add two new entries to the unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";

    std::cout << "\nOutput values by key:\n"
                 "The HEX of color RED is:["
              << u["RED"]
              << "]\n"
                 "The HEX of color BLACK is:["
              << u["BLACK"] << "]\n\n";

    std::cout << "Use operator[] with non-existent key to insert a new "
                 "key-value pair:\n";
    print_key_value("new_key", u["new_key"]);

    std::cout << "\nIterate and print key-value pairs, using `auto`;\n"
                 "new_key is now one of the keys in the map:\n";
    for (const auto& n : u)
        print_key_value(n.first, n.second);
}

int main() {
    unorderedMap();
}