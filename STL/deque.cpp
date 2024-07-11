/*
template<
    class T,
    class Allocator = std::allocator<T>
> class deque;

std::deque (double-ended queue) is an indexed sequence container that allows
fast insertion and deletion at both its beginning and its end. In addition,
insertion and deletion at either end of a deque never invalidates pointers or
references to the rest of the elements.

std::deque （双端队列）是一个索引序列容器，允许在其开头和结尾快速插入和删除。
此外，在双端队列任一端插入和删除永远不会使对其余元素的指针或引用无效。

As opposed to std::vector, the elements of a deque are not stored contiguously:
typical implementations use a sequence of individually allocated fixed-size
arrays, with additional bookkeeping, which means indexed access to deque must
perform two pointer dereferences, compared to vector's indexed access which
performs only one.

与 std::vector 不同，双端队列的元素不是连续存储的：
典型的实现使用一系列单独分配的固定大小数组，并进行额外的簿记，
这意味着与vector相比，对双端队列的索引访问必须执行两次指针取消引用,
而 vector 索引访问仅执行一项。

The storage of a deque is automatically expanded and contracted as needed.
Expansion of a deque is cheaper than the expansion of a std::vector because it
does not involve copying of the existing elements to a new memory location. On
the other hand, deques typically have large minimal memory cost; a deque holding
just one element has to allocate its full internal array (e.g. 8 times the
object size on 64-bit libstdc++; 16 times the object size or 4096 bytes,
whichever is larger, on 64-bit libc++).

双端队列的存储会根据需要自动扩展和收缩。双端队列的扩展比 std::vector
的扩展便宜，因为它不涉及将现有元素复制到新的内存位置。
另一方面，双端队列通常具有较大的最小内存成本；
仅包含一个元素的双端队列必须分配其完整的内部数组
（例如，在 64 位 libstdc++ 上为对象大小的 8 倍；
在 64 位 libc++ 上为对象大小的 16 倍或 4096 字节，以较大者为准）。

The complexity (efficiency) of common operations on deques is as follows:

双端队列常见操作的复杂度（效率）如下：

Random access - constant O(1).
随机访问 - 常数 O(1)。

Insertion or removal of elements at the end or beginning - constant O(1).
在末尾或开头插入或删除元素 - 常数 O(1)。

Insertion or removal of elements - linear O(n).
插入或删除元素 - 线性 O(n)。

std::deque meets the requirements of Container, AllocatorAwareContainer,
SequenceContainer and ReversibleContainer.

Member functions
(constructor)	constructs the deque
    (public member function)
(destructor)	destructs the deque
    (public member function)
operator=	assigns values to the container
    (public member function)
assign	assigns values to the container
    (public member function)
assign_range	assigns a range of values to the container
(C++23)	(public member function)
get_allocator	returns the associated allocator
    (public member function)
Element access
at	access specified element with bounds checking
    (public member function)
operator[]	access specified element
    (public member function)
front	access the first element
    (public member function)
back	access the last element
    (public member function)
Iterators
begincbegin	returns an iterator to the beginning
(C++11)	(public member function)
endcend	returns an iterator to the end
(C++11)	(public member function)
rbegincrbegin	returns a reverse iterator to the beginning
(C++11)	(public member function)
rendcrend	returns a reverse iterator to the end
(C++11)	(public member function)
Capacity
empty	checks whether the container is empty
    (public member function)
size	returns the number of elements
    (public member function)
max_size	returns the maximum possible number of elements
    (public member function)
shrink_to_fit	reduces memory usage by freeing unused memory
(DR*)	(public member function)
Modifiers
clear	clears the contents
    (public member function)
insert	inserts elements
    (public member function)
insert_range	inserts a range of elements
(C++23)	(public member function)
emplace	constructs element in-place
(C++11)	(public member function)
erase	erases elements
    (public member function)
push_back	adds an element to the end
    (public member function)
emplace_back	constructs an element in-place at the end
(C++11)	(public member function)
append_range	adds a range of elements to the end
(C++23)	(public member function)
pop_back	removes the last element
    (public member function)
push_front	inserts an element to the beginning
    (public member function)
emplace_front	constructs an element in-place at the beginning
(C++11)	(public member function)
prepend_range	adds a range of elements to the beginning
(C++23)	(public member function)
pop_front	removes the first element
    (public member function)
resize	changes the number of elements stored
    (public member function)
swap	swaps the contents
    (public member function)

*/

// CPP Program to implement Deque in STL
#include <deque>
#include <iostream>

#include <cassert>
#include <vector>
using namespace std;

void showdq(deque<int> g) {
    deque<int>::iterator it;
    for(it = g.begin(); it != g.end(); ++it) cout << '\t' << *it;
    cout << '\n';
}

int tryDeque() {
    deque<int> gquiz;
    gquiz.push_back(10);
    gquiz.push_front(20);
    gquiz.push_back(30);
    gquiz.push_front(15);
    cout << "The deque gquiz is : ";
    showdq(gquiz);

    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.max_size() : " << gquiz.max_size();

    cout << "\ngquiz.at(2) : " << gquiz.at(2);
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();

    cout << "\ngquiz.pop_front() : ";
    gquiz.pop_front();
    showdq(gquiz);

    cout << "\ngquiz.pop_back() : ";
    gquiz.pop_back();
    showdq(gquiz);

    return 0;
}

void test_deque_member_functions() {
    // operator=
    {
        std::deque<int> d1 = { 1, 2, 3 };
        std::deque<int> d2;
        d2 = d1;
        assert(d2 == d1);
    }

    // assign
    {
        std::deque<int> d;
        d.assign(5, 10);
        assert(d.size() == 5);
        assert(d.front() == 10 && d.back() == 10);
    }

    // get_allocator
    {
        std::deque<int> d;
        auto alloc = d.get_allocator();
        std::deque<int> d2(alloc);
        d2.push_back(1);
        assert(d2.front() == 1);
    }

    // assign_range (C++23)
    // {
    //     std::deque<int> d;
    //     std::vector<int> v = {1, 2, 3};
    //     d.assign_range(v.begin(), v.end());
    //     assert(d.size() == 3);
    //     assert(d.front() == 1 && d.back() == 3);
    // }
}

void test_deque_element_access() {
    std::deque<int> d = { 1, 2, 3, 4, 5 };

    // at
    assert(d.at(2) == 3);

    // operator[]
    assert(d[2] == 3);

    // front
    assert(d.front() == 1);

    // back
    assert(d.back() == 5);
}

void test_deque_iterators() {
    std::deque<int> d = { 1, 2, 3, 4, 5 };

    // begin, cbegin (C++11)
    assert(*d.begin() == 1);
    assert(*d.cbegin() == 1);

    // end, cend (C++11)
    assert(*(d.end() - 1) == 5);
    assert(*(d.cend() - 1) == 5);

    // rbegin, crbegin (C++11)
    assert(*d.rbegin() == 5);
    assert(*d.crbegin() == 5);

    // rend, crend (C++11)
    assert(*(d.rend() - 1) == 1);
    assert(*(d.crend() - 1) == 1);
}

void test_deque_capacity() {
    std::deque<int> d;

    // empty
    assert(d.empty());

    // size
    d.push_back(1);
    assert(d.size() == 1);

    // max_size
    assert(d.max_size() > 0);

    // shrink_to_fit (DR*)
    d.push_back(2);
    d.shrink_to_fit();  // No direct way to assert this, relies on behavior
}

void test_deque_modifiers() {
    std::deque<int> d = { 1, 2, 3, 4, 5 };

    // clear
    d.clear();
    assert(d.empty());

    // insert
    d.insert(d.begin(), 10);
    assert(d.front() == 10);

    // insert_range (C++23)
    // std::vector<int> v = {1, 2, 3};
    // d.insert_range(d.end(), v.begin(), v.end());
    // assert(d.back() == 3 && d.front() == 10);
    d.insert(d.begin(), 15);

    // emplace (C++11)
    d.emplace(d.begin() + 1, 20);
    assert(d[1] == 20);

    showdq(d);
    // erase
    d.erase(d.begin() + 1);
    showdq(d);
    assert(d[1] != 20);

    // push_back
    d.push_back(30);
    assert(d.back() == 30);

    // emplace_back (C++11)
    d.emplace_back(40);
    assert(d.back() == 40);

    // append_range (C++23)
    // std::deque<int> d2 = {50, 60};
    // d.append_range(d2.begin(), d2.end());
    // assert(d.back() == 60);

    // pop_back
    d.pop_back();
    assert(d.back() != 60);

    // push_front
    d.push_front(70);
    assert(d.front() == 70);

    // emplace_front (C++11)
    d.emplace_front(80);
    assert(d.front() == 80);

    // prepend_range (C++23)
    // d.prepend_range(d2.begin(), d2.end());
    // assert(d.front() == 50);

    // pop_front
    d.pop_front();
    assert(d.front() != 50);

    // resize
    d.resize(10, 100);
    assert(d.size() == 10);

    // swap
    std::deque<int> d3 = { 1, 2, 3 };
    d.swap(d3);
    assert(d.size() == 3 && d3.size() == 10);
}

void test_modifiers() {
    // clear
    {
        std::deque<int> d = { 1, 2, 3, 4, 5 };
        d.clear();
        assert(d.empty());
    }

    // insert
    {
        std::deque<int> d = { 1, 2, 3, 5 };
        d.insert(d.begin() + 3, 4);
        assert(d[3] == 4);
    }

    // // insert_range (C++23)
    // {
    //     std::deque<int> d = {1, 2, 6};
    //     std::vector<int> vec = {3, 4, 5};
    //     d.insert_range(d.begin() + 2, vec.begin(), vec.end());
    //     assert((d == std::deque<int>{1, 2, 3, 4, 5, 6}));
    // }

    // emplace
    {
        std::deque<int> d = { 1, 2, 4 };
        d.emplace(d.begin() + 2, 3);
        assert(d[2] == 3);
    }

    // erase
    {
        std::deque<int> d = { 1, 2, 3, 4, 5 };
        d.erase(d.begin() + 1);
        assert(d == std::deque<int>({ 1, 3, 4, 5 }));
    }

    // push_back
    {
        std::deque<int> d;
        d.push_back(1);
        assert(d.back() == 1);
    }

    // emplace_back
    {
        std::deque<int> d;
        d.emplace_back(1);
        assert(d.back() == 1);
    }

    // pop_back
    {
        std::deque<int> d = { 1, 2, 3, 4, 5 };
        d.pop_back();
        assert(d.back() == 4);
    }
    // push_front
    {
        std::deque<int> d;
        d.push_front(1);
        assert(d.front() == 1);
    }

    // emplace_front
    {
        std::deque<int> d;
        d.emplace_front(1);
        assert(d.front() == 1);
    }

    // pop_front
    {
        std::deque<int> d = { 1, 2, 3, 4, 5 };
        d.pop_front();
        assert(d.front() == 2);
    }

    // resize
    {
        std::deque<int> d = { 1, 2, 3, 4, 5 };
        d.resize(10, 100);
        assert(d.size() == 10);
        assert(d.back() == 100);
    }

    // swap
    {
        std::deque<int> d1 = { 1, 2, 3 };
        std::deque<int> d2 = { 4, 5, 6 };
        d1.swap(d2);
        assert(d1 == (std::deque<int>{ 4, 5, 6 }));
        assert(d2 == (std::deque<int>{ 1, 2, 3 }));
    }
}
int main() {
    // tryDeque();
    test_deque_member_functions();
    test_deque_element_access();
    test_deque_iterators();
    test_deque_capacity();
    test_deque_modifiers();
    test_modifiers();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}
