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