n, m = list(map(int, input().split()))
# print(n, m)
cache = []
for i in range(n):
    cache.append(list(map(int, input().split())))
    # print(cache[i])

for i in range(n):
    has = False
    for j in range(n):
        ok = True
        for k in range(m):
            if cache[j][k] <= cache[i][k]:
                ok = False
                break
        if ok:
            print(j+1)
            has = True
            break
    if not has:
        print(0)
