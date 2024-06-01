# 垦田计划
n, m, k = map(int, input().strip().split())

# 贪心： 选时长最大的，投入资源最少的
import heapq  # can use in csp

data = []

for i in range(n):
    l = list(map(int, input().strip().split()))
    l[0] = -l[0]
    l.append(i)
    heapq.heappush(data, l)
    # data.append(list(map(int, input().strip().split())))

# nk = -k

# d = heapq.heappop(data)
# heapq.heappush(data, d)
# print(data)
# while k >= d[1]:
#     k -= d[1]
#     d[0] = d[0] + 1
#     heapq.heappush(data, d)
#     print(data)
#     d = heapq.heappop(data)
# print(data)

while True:
    d = heapq.heappop(data)
    # print(d)
    # print(m)

    if m < d[1]:
        heapq.heappush(data, d)
        break
    m = m - d[1]
    d[0] = d[0] + 1
    heapq.heappush(data, d)
    # print(data)
# print(data)

max_d = -heapq.heappop(data)[0]
if max_d < k:
    max_d = k
print(max_d)


"""

4 9 2
6 1
5 1
6 2
7 1
"""
