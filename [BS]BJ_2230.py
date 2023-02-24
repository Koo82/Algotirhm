# two-pointer problem
# left and right starts from 0, 0
# if difference between values bigger than threshold, increase right else increase left
# binary search transversion, 고민을 꽤함

import sys
rdln = sys.stdin.readline
inf = 0x7fffffff

def input_data():
    n, m = map(int, rdln().split())
    arr = [int(rdln()) for _ in range(n)]
    arr.sort()
    return n, m, arr

def check():
    sol = inf
    l, r = 0, 0
    while l < n and r < n:
        if (arr[r] - arr[l]) < m:
            r += 1 
        else:
            sol = min(sol, arr[r]-arr[l])
            l += 1
    return sol

n, m, arr = input_data()
sys.stdout.write(f"{check()}\n")

