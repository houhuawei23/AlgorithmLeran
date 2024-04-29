# a = map(int, input().split())
# print(type(a))
n, m = map(int, input().split())
dx = 0; dy =0
for i in range(n):
    a, b = map(int, input().split())
    dx += a
    dy += b
xs = [0 for i in range(m)]
ys = [0 for i in range(m)]

for i in range(m):
    xs[i], ys[i] = map(int, input().split())

for i in range(m):
    print(f"{xs[i] + dx} {ys[i] + dy}")
# print(f"{x + dx} {y + dy}")

# # n = int(n)
# # m = int(m)

# print(n + m)