/*
https://en.cppreference.com/w/cpp/algorithm/upper_bound
https://blog.csdn.net/weixin_45031801/article/details/137544229
*/

#include <algorithm>
#include <cassert>
#include <complex>
#include <iostream>
#include <vector>

struct PriceInfo {
    double price;
};

void testLowerBound() {
    const std::vector<int> data{1, 2, 4, 5, 5, 6};

    for (int i = 0; i < data.size(); i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 8; ++i) {
        // Search for first element x such that i ≤ x
        auto lower = std::lower_bound(data.begin(), data.end(), i);

        std::cout << i << " ≤ ";
        lower != data.end() ? std::cout << *lower << " at index "
                                        << std::distance(data.begin(), lower)
                            : std::cout << "not found";
        std::cout << '\n';
    }

    std::vector<PriceInfo> prices{{100.0}, {101.5}, {102.5}, {102.5}, {107.3}};

    for (const double to_find : {102.5, 110.2}) {
        auto prc_info =
            std::lower_bound(prices.begin(), prices.end(), to_find,
                             [](const PriceInfo& info, double value) {
                                 return info.price < value;
                             });

        prc_info != prices.end() ? std::cout << prc_info->price << " at index "
                                             << prc_info - prices.begin()
                                 : std::cout << to_find << " not found";
        std::cout << '\n';
    }

    using CD = std::complex<double>;
    std::vector<CD> nums{{1, 0}, {2, 2}, {2, 1}, {3, 0}};
    auto cmpz = [](CD x, CD y) { return x.real() < y.real(); };
#ifdef __cpp_lib_algorithm_default_value_type
    auto it = std::lower_bound(nums.cbegin(), nums.cend(), {2, 0}, cmpz);
#else
    auto it = std::lower_bound(nums.cbegin(), nums.cend(), CD{2, 0}, cmpz);
#endif
    assert((*it == CD{2, 2}));
}

void testUpperBound() {
    std::cout << "testUpperBound: " << std::endl;
    const std::vector<int> data{1, 2, 4, 5, 5, 6};

    for (int i = 0; i < data.size(); i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 7; ++i) {
        // Search first element that is greater than i
        auto upper = std::upper_bound(data.begin(), data.end(), i);

        std::cout << i << " < ";
        upper != data.end() ? std::cout << *upper << " at index "
                                        << std::distance(data.begin(), upper)
                            : std::cout << "not found";
        std::cout << '\n';
    }

    std::vector<PriceInfo> prices{{100.0}, {101.5}, {102.5}, {102.5}, {107.3}};

    for (double to_find : {102.5, 110.2}) {
        auto prc_info =
            std::upper_bound(prices.begin(), prices.end(), to_find,
                             [](double value, const PriceInfo& info) {
                                 return value < info.price;
                             });

        prc_info != prices.end() ? std::cout << prc_info->price << " at index "
                                             << prc_info - prices.begin()
                                 : std::cout << to_find << " not found";
        std::cout << '\n';
    }

    using CD = std::complex<double>;
    std::vector<CD> nums{{1, 0}, {2, 2}, {2, 1}, {3, 0}, {3, 1}};
    auto cmpz = [](CD x, CD y) { return x.real() < y.real(); };
#ifdef __cpp_lib_algorithm_default_value_type
    auto it = std::upper_bound(nums.cbegin(), nums.cend(), {2, 0}, cmpz);
#else
    auto it = std::upper_bound(nums.cbegin(), nums.cend(), CD{2, 0}, cmpz);
#endif
    assert((*it == CD{3, 0}));
}

int main() {
    testLowerBound();
    testUpperBound();
    return 0;
}