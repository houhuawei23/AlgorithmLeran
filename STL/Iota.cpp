#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>

class BigData  // inefficient to copy
{
    int data[1024]; /* some raw data */
public:
    explicit BigData(int i = 0) { data[0] = i; /* ... */ }
    operator int() const { return data[0]; }
    BigData& operator=(int i) {
        data[0] = i;
        return *this;
    }
    /* ... */
};

int main() {
    std::list<BigData> l(10);
    std::iota(l.begin(), l.end(), -4);

    std::vector<std::list<BigData>::iterator> v(l.size());
    std::iota(v.begin(), v.end(), l.begin());
    // Vector of iterators (to original data) is used to avoid expensive
    // copying, and because std::shuffle (below) cannot be applied to a
    // std::list directly.

    std::shuffle(v.begin(), v.end(), std::mt19937{ std::random_device{}() });

    std::cout << "Original contents of the list l:\t";
    for(const auto& n : l) std::cout << std::setw(2) << n << ' ';
    std::cout << '\n';

    std::cout << "Contents of l, viewed via shuffled v:\t";
    for(const auto i : v) std::cout << std::setw(2) << *i << ' ';
    std::cout << '\n';
}