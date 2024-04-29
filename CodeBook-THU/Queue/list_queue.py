m,n = map(int, input().split())
qs = list(map(int, input().split()))

mem = []
cnt = 0
for q in qs:
    if q not in mem:
        if len(mem) == m:
            mem = mem[1:]
        mem.append(q)
        cnt+=1

print(cnt)
     
