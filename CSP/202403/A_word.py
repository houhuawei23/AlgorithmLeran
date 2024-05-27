n, m = map(int, input().strip().split())
eassys = []

eassy_cnts = [0 for _ in range(m + 1)]

word_cnts = [0 for _ in range(m + 1)]
for i in range(n):
    line = list(map(int, input().strip().split()))[1:]
    for w in line:
        word_cnts[w] += 1
    for w in range(1, m + 1):
        if w in line:
            eassy_cnts[w] += 1
    eassys.append(line)
# for i in range(m):
#     word_cnts[i] = i

# print(eassys)
# print(eassy_cnts)
# print(word_cnts)

for i in range(1, m + 1):
    print(eassy_cnts[i], word_cnts[i])
