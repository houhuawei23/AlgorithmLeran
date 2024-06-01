n, m = map(int, input().strip().split())

setA = set()
setB = set()

eassyA = input().strip().split()
eassyB = input().strip().split()

for w in eassyA:
    setA.add(w.lower())
for w in eassyB:
    setB.add(w.lower())

jiaoAB = setA.intersection(setB)
bingAB = setA.union(setB)

# print(setA, setB)
# print(jiaoAB, bingAB)

print(len(jiaoAB))
print(len(bingAB))