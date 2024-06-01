

def main():
    N = 35
    M = 300005
    
    n, x = map(int, input().split())
    # SUM = 0
    arr = [0 for i in range(N)]
    f = [[0 for i in range(M)] for i in range(N)]
    
    for i in range(1, n + 1):
        arr[i] = int(input())
        
    SUM = sum(arr)
    c = SUM - x
    
    for i in range(1, n + 1):
        for j in range(0, c + 1):
            if j >= arr[i]:
                f[i][j] = max(f[i-1][j], f[i-1][j - arr[i]] + arr[i])
            else:
                f[i][j] = f[i-1][j]
    
    print(sum - f[n][c])

# not allowed in csp
import numpy as np

def main2():
    N = 35
    M = 300005
    
    n, x = map(int, input().split())
    
    arr = np.zeros(N, dtype=int)
    f = np.zeros((N, M), dtype=int)

    SUM = 0
    for i in range(1, n + 1):
        arr[i] = int(input())
        SUM += arr[i]    
    
    c = SUM - x
    
    for i in range(1, n + 1):
        for j in range(0, c + 1):
            if j >= arr[i]:
                f[i][j] = max(f[i-1][j], f[i-1][j - arr[i]] + arr[i])
            else:
                f[i][j] = f[i-1][j]
    
    print(SUM - f[n][c])
    
def main3():
    N = 35
    M = 300005
    
    n, x = map(int, input().split())
    # sum = 0
    arr = [0 for i in range(N)]
    f = [0 for i in range(M)] 
    
    for i in range(1, n + 1):
        arr[i] = int(input())
        
    SUM = sum(arr)
    c = SUM - x
    
    for i in range(1, n + 1):
        for j in range(c, arr[i]-1, -1):
            f[j] = max(f[j], f[j - arr[i]] + arr[i])
    
    print(SUM - f[c])

main3()