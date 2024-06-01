"""
40/100
time and memory exceeded.
"""

DEBUG = False

c, m, n = map(int, input().strip().split())

# 1 ~ c
grids = [0 for _ in range(c + 1)]

for i in range(m):
    x, w = map(int, input().strip().split())
    assert x <= c and 1 <= w <= 4
    grids[x] = w

ops = [0 for _ in range(n)]

for i in range(n):
    ops[i] = int(input().strip())

if DEBUG:
    print(c, m, n)
    print(grids)
    print(ops)


def calc_water_grid_num(grids):
    cnt = 0
    for i in range(1, c + 1):
        if grids[i] > 0:
            cnt += 1
    return cnt


# num = calc_water_grid_num(grids)
# print(num)
# exit()


def sim(p):
    """
    return num of grid with water
    """
    if DEBUG:
        print(f"sim on: {p}")

    grids[p] += 1

    while True:
        if DEBUG:
            print("grids: ", grids)
        changed = False
        for i in range(1, c + 1):
            if grids[i] >= 5:
                changed = True
                # spread
                grids[i] = 0
                # left
                for l in range(i - 1, 0, -1):
                    if grids[l] != 0:
                        grids[l] += 1
                        break
                # right
                for r in range(i + 1, c + 1):
                    if grids[r] != 0:
                        grids[r] += 1
                        break
                break
        if not changed:
            break
    num = calc_water_grid_num(grids)
    # print(num)
    return num


# sim(3)

res = []
for p in ops:
    num = sim(p)
    res.append(num)

for e in res:
    print(e)
