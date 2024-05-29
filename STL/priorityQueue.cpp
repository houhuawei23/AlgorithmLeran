/*
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;


The priority queue is a container adaptor that provides constant time lookup of
the largest (by default) element, at the expense of logarithmic insertion and
extraction.

优先级队列是一个容器适配器，它提供最大（默认）元素的恒定时间查找，但代价是对数插入和提取。

A user-provided Compare can be supplied to change the ordering, e.g. using
std::greater<T> would cause the smallest element to appear as the top().

可以提供用户提供的 Compare 来更改顺序，例如使用 std::greater<T>
会导致最小的元素显示为 top()。
default: large to small

Working with a priority_queue is similar to managing a heap in some random
access container, with the benefit of not being able to accidentally invalidate
the heap.

使用 priority_queue 类似于管理某些随机访问容器中的堆，其优点是不会意外使堆无效。


T	-	The type of the stored elements. The program is ill-formed if T is not
the same type as Container::value_type.

Container	-	The type of the underlying container to use to store the
elements. The container must satisfy the requirements of SequenceContainer, and
its iterators must satisfy the requirements of LegacyRandomAccessIterator.
Additionally, it must provide the following functions with the usual semantics:
front(), e.g., std::vector::front(),
push_back(), e.g., std::deque::push_back(),
pop_back(), e.g., std::vector::pop_back().
The standard containers std::vector (including std::vector<bool>) and std::deque
satisfy these requirements.

Compare	-	A Compare type providing a strict weak ordering.
Note that the Compare parameter is defined such that it returns true if its
first argument comes before its second argument in a weak ordering. But because
the priority queue outputs largest elements first, the elements that "come
before" are actually output last. That is, the front of the queue contains the
"last" element according to the weak ordering imposed by Compare.
*/

#include <functional>
#include <iostream>
#include <queue>
#include <string_view>
#include <vector>

template <typename T>
void pop_println(std::string_view rem, T& pq) {
    std::cout << rem << ": ";
    for (; !pq.empty(); pq.pop())
        std::cout << pq.top() << ' ';
    std::cout << '\n';
}

template <typename T>
void println(std::string_view rem, const T& v) {
    std::cout << rem << ": ";
    for (const auto& e : v)
        std::cout << e << ' ';
    std::cout << '\n';
}

void priorityQueue() {
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    println("data", data);

    std::priority_queue<int> max_priority_queue;

    // Fill the priority queue.
    for (int n : data)
        max_priority_queue.push(n);

    pop_println("max_priority_queue", max_priority_queue);

    // std::greater<int> makes the max priority queue act as a min priority
    // queue.
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        min_priority_queue1(data.begin(), data.end());

    pop_println("min_priority_queue1", min_priority_queue1);

    // Second way to define a min priority queue.
    std::priority_queue min_priority_queue2(data.begin(), data.end(),
                                            std::greater<int>());

    pop_println("min_priority_queue2", min_priority_queue2);

    // Using a custom function object to compare elements.
    struct {
        bool operator()(const int l, const int r) const { return l > r; }
    } customLess;

    std::priority_queue custom_priority_queue(data.begin(), data.end(),
                                              customLess);

    pop_println("custom_priority_queue", custom_priority_queue);

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)>
        lambda_priority_queue(cmp);

    for (int n : data)
        lambda_priority_queue.push(n);

    pop_println("lambda_priority_queue", lambda_priority_queue);
}

int main() {
    priorityQueue();
    return 0;
}