n, m  = map(int, input().split())
a = list(map(int, input().split()))

for i in range(n):
    b = m % a[i]
    m = m // a[i]
    print(b, end=" ")