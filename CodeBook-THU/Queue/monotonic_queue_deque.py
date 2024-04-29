# 超时
# 比C++慢5倍左右，已经O(n)，基本无法再优化了
# 内存20倍
# deque 高度节省内存地从 deque 的任一端添加和弹出条目，在两个方向上的大致性能均为 O(1)。
from collections import deque

def main3():
    n, k = map(int, input().split())
    
    arr = list(map(int, input().split()))
    
    q1 = deque()
    q2 = deque()
    res1 = []
    res2 = []
    for i, e in enumerate(arr):
        while q1 and arr[q1[-1]] >e:
            q1.pop()
        while q2 and arr[q2[-1]] < e:
            q2.pop()
            
        q1.append(i)
        q2.append(i)
        if i >= k-1:
            if q1[0] + k == i:
                q1.popleft()
            if q2[0] + k == i:
                q2.popleft()
            res1.append(arr[q1[0]])
            res2.append(arr[q2[0]])
            
    for e in res1:
        print(e, end=" ")
    print()
    for e in res2:
        print(e, end=" ")


def main2():
    n, k = map(int, input().split())
    
    arr = list(map(int, input().split()))
    
    q1 = deque()
    q2 = deque()
    res1 = []
    res2 = []
    for i, e in enumerate(arr):
        while q1 and arr[q1[-1]] >e:
            q1.pop()
        while q2 and arr[q2[-1]] < e:
            q2.pop()
            
        q1.append(i)
        q2.append(i)
        if i >= k-1:
            while q1 and q1[0] + k <= i:
                q1.popleft()
            while q2 and q2[0] + k <= i:
                q2.popleft()
            res1.append(arr[q1[0]])
            res2.append(arr[q2[0]])
            
    for e in res1:
        print(e, end=" ")
    print()
    for e in res2:
        print(e, end=" ")

def main1():
    n, k = map(int, input().split())
    
    arr = list(map(int, input().split()))
    
    q = deque()
    
    
    for i, e in enumerate(arr):
        while q and arr[q[-1]] >e:
            q.pop()
        q.append(i)
        if i >= k-1:
            while q and q[0] + k <= i:
                q.popleft()
            print(f"{arr[q[0]]}", end=" ")
    print()
    q.clear()
    for i, e in enumerate(arr):
        # print(f"q: {q}")
        while q and arr[q[-1]] < e:
            q.pop()
        q.append(i)
        if i >= k-1:
            while q and q[0] + k <= i:
                q.popleft()
            print(f"{arr[q[0]]}", end=" ")


main3()