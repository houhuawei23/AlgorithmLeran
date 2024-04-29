from copy import deepcopy

N = int(input())


def f(l: list):
    if len(l) == N:
        # print(l)
        for e in l:
            print(e, end=" ")
        print()
        return 
    # print(l)
    for i in range(1, N + 1):
        if i in l:
            continue
        ll = deepcopy(l)
        ll.append(i)
        f(ll)

l = []
f(l)