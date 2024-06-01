"""
国际象棋在对局时，同一局面连续或间断出现3次或3次以上，可由任意一方提出和棋。

"""

n = int(input())

jumians = []
res = []
for i in range(n):
    jumian = []
    for j in range(8):
        line = input().strip()
        jumian.append(line)
    cnt = 1

    for jm in jumians:
        isok = True
        for k in range(8):
            if jm[k] != jumian[k]:
                isok = False
                break
        if isok:
            cnt = cnt + 1

    res.append(cnt)
    jumians.append(jumian)

for cnt in res:
    print(cnt)
