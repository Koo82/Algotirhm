import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().rstrip().split()))

M = int(sys.stdin.readline())
arr_r = list(map(int, sys.stdin.readline().rstrip().split()))

arr = sorted(arr)
mid = len(arr)//2

def binary_search(num, key):
    L = 0
    R = num-1
    while L <= R:
        next_div = (L+R)//2
        if arr[next_div] > key:
            R = next_div-1
        elif arr[next_div] < key:
            L = next_div+1
        else:
            return 1
    return 0

for key in arr_r:
    sys.stdout.write(f"{binary_search(N, key)}\n")

