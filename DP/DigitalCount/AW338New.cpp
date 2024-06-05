/*计数问题
https://www.acwing.com/problem/content/340/
*/
#include <bits/stdc++.h>
using namespace std;

// int a, b;
vector<int> as;
vector<int> bs;

bool debug = false;

int power10(int i) {
    int res = 1;
    while(i--) res *= 10;
    return res;
}
int get(const vector<int>& digits, int l, int r) {
    if(debug) {
        printf("digits: [");
        for(auto digit : digits) {
            printf("%d ", digit);
        }
        printf("], l=%d, r=%d\n", l, r);
    }
    assert(0 <= l);
    if(l > r or l > digits.size() or r > digits.size()) {
        return 0;
    }
    int res = 0;
    for(int i = l; i <= r; i++) {
        res = res * 10 + digits[i];
    }

    if(debug) {
        printf("get res: %d\n", res);
    }
    return res;
}
/*
x
idx:    0 1 2 3 4 5 6, maxIdx = 6
digits: a b c d e f g
when idx = 3: num form 1 to abcdef, the num[idx] == x, numbers
consider all numbers like: xxx z yyy
1. xxx: from 100 to abc - 1, z = 1, yyy can be any (000 to 999)
    - number:
2. xxx = abc
    2.1. z < digits[idx], yyy can be any (000 to 999), power10(3)
        - number: power10(maxIdx - idx)
    2.2. z = digits[idx], yyy from 000 to efg
        - number: get(idx + 1, maxIdx)
    2.3. z > digitis[idxx], no ok
        - number: 0
becareful for digit 0.
idx=0:
    if x == 0:
        res = 0
    else:
        res = power10(maxIdx - idx)
idx >= 1:
    case1Num = get(digits, 0, idx - 1) * power10(maxIdx - idx);

    if (x == digits[idx]):
        case2Num = get(digits, idx + 1, maxIdx) + 1;
    else if (x < digits[idx]):
        case2Num = power10(maxIdx - idx);
    else:
        case2Num = 0

    res = case1Num + case2Num


*/
int count(const int n, const int x) {
    /* 计算 1 ~ n 所有数中出现 digit x 的 个数 */
    assert(x >= 0 and x < 10);
    if(n == 0) {
        return 0;
    }
    vector<int> digits; /* split n to vector in bits, reversed order */
    {
        int tn = n;
        while(tn) {
            digits.push_back(tn % 10);
            tn /= 10;
        }
    }

    reverse(digits.begin(), digits.end()); /* positive order */

    if(debug) {
        printf("count(n: %d, x: %d)\n", n, x);
        printf("digits: \n");
        for(auto digit : digits) {
            printf("%d ", digit);
        }
        printf("\n");
    }

    const int maxIdx = digits.size() - 1;

    vector<int> OccurNumber;

    int sum = 0;
    for(int idx = 0; idx <= maxIdx; idx++) {
        if(debug) {
            printf("== idx: %d, digitis[%d]: %d\n", idx, idx, digits[idx]);
        }

        int pre = get(digits, 0, idx - 1);
        int next = get(digits, idx + 1, maxIdx);
        int nextBitsLen = maxIdx - idx;
        int nextBitsPower = power10(nextBitsLen);

        int case1Num = 0;

        /*
        a(abcdefg) and b(xxxeyyy), can be seen as 0abcdefg and 0xxxeyyy, the
        index of 0 is -1 so,
        when idx = 0:
            - case1 always false (a[-1] == b[-1]), so case1Num = 0;
            - case2:
                - if x == 0, no 'gard' before this Zero, so case2Num = 0;
                - if x != 0, normal case.
        when idx >=1:
            - case1:
                - if x == 0, this Zero has no 'gard' when xxx == 0,
                    so need to delete 1 from pre
                - if x != 0, normal case
            - case2:
                - becase case require b[0: idx-1] == a[0: idx - 1], and b[0]
                  must not be Zero/0, so the zero following b[0] must be
                  'garded' by b[0], so all zero are valid. do not need more
                  special treatment.
        */

        /* idx = 0, case1Num = 0 */
        if(idx >= 1) {
            if(x == 0) {
                /* x == 0, pre - 1 for not include 0, like:
                ** xxxeyyy, xxx from 1 to pre, only pre - 1 */
                case1Num = (pre - 1) * nextBitsPower;
            } else {
                /* x != 0, xxx can be from 0 to pre */
                case1Num = pre * nextBitsPower;
            }
        }

        int case2Num = 0;
        if(idx == 0 and x == 0) {
            /* this Zero(x) is not 'garded' or 'protected',
            ** it has no leading non-zero digit */
            case2Num = 0;
        } else if(x == digits[idx]) {
            /* yyy can value in range [0 ~ next], total next + 1*/
            if(debug) printf("digits[idx] == x\n");
            case2Num = next + 1;
        } else if(x < digits[idx]) {
            /* yyy can value in range [0 ~ 999..], total 10^nextBitsLen */
            if(debug) printf("digits[idx] > x\n");
            case2Num = nextBitsPower;
        } else {
            /* digits[idx] < x, Zero*/
            if(debug) printf("digits[idx] < x, Zero\n");
        }

        if(debug) printf("case1: %d, case2: %d\n", case1Num, case2Num);
        int res = case1Num + case2Num;
        OccurNumber.push_back(res);
    }

    if(debug) printf("OccurNumber:\n");
    for(auto occcurNum : OccurNumber) {
        if(debug) printf("%d\n", occcurNum);
        sum += occcurNum;
    }
    if(debug) printf("sum: %d\n", sum);
    assert(sum == accumulate(OccurNumber.begin(), OccurNumber.end(), 0));
    return sum;
}

int main() {
    while(true) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a == 0 and b == 0) {
            break;
        }
        if(a > b) swap(a, b);
        as.push_back(a);
        bs.push_back(b);
    }

    for(int i = 0; i < as.size(); i++) {
        if(debug) printf("%d %d\n", as[i], bs[i]);
        for(int x = 0; x <= 9; x++) {
            if(debug) {
                printf("%d ~ %d, x(%d), %d \n", as[i], bs[i], x,
                       count(bs[i], x) - count(as[i] - 1, x));
            } else {
                printf("%d ", count(bs[i], x) - count(as[i] - 1, x));
            }
        }
        printf("\n");
    }
}

/*
1 10
0 0

1 2 1 1 1 1 1 1 1 1

输入样例：
1 10
44 497
346 542
1199 1748
1496 1403
1004 503
1714 190
1317 854
1976 494
1001 1960
0 0
输出样例：
1 2 1 1 1 1 1 1 1 1
85 185 185 185 190 96 96 96 95 93
40 40 40 93 136 82 40 40 40 40
115 666 215 215 214 205 205 154 105 106
16 113 19 20 114 20 20 19 19 16
107 105 100 101 101 197 200 200 200 200
413 1133 503 503 503 502 502 417 402 412
196 512 186 104 87 93 97 97 142 196
398 1375 398 398 405 499 499 495 488 471
294 1256 296 296 296 296 287 286 286 247
*/