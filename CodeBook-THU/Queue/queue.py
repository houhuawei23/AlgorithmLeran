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

from queue import PriorityQueue as PQ




def main():
    n, k = map(int, input().split())
    
    arr = list(map(int, input().split()))
    pq1 = PQ()
    pq2 = PQ()
    res1 = []
    res2 = []

    for i, e in enumerate(arr):
        pq1.put(e)
