from copy import deepcopy

N = int(input())


def f(l: list):
    if len(l) == N:
        for e in l:
            print(e, end=" ")
        print()
        return 
    for i in range(1, N + 1):
        if i in l:
            continue
        ll = deepcopy(l)
        ll.append(i)
        f(ll)

l = []
f(l)