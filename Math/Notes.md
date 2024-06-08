取余与整除运算性质
```
(a + b) % c == (a % c + b % c) % c
(a * b) % c == (a % c * b % c) % c

for general condition, 
(a + b) // c != (a // c + b // c)
(a * b) // c != (a // c * b // c)

let r1 = a % c, r2 = b % c
1. 
if r1 + r2 < c:
    (a + b) // c == (a // c + b // c)
if r1 + r2 >= c:
    (a + b) // c == (a // c + b // c) + 1

2. ? why
if r1 == 0 or r2 == 0
    or
if r1*r2 < c and (k*c*r2 + m*c*r1) % c == 0:
    (a * b) // c == (a // c * b // c)
```