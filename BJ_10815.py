import sys
DEBUG = True

def log(message):
    if DEBUG:
        print(message)


def binary_search(val):
    L = 0
    R = N-1

    while L <= R:
        mid = (L+R) // 2
        if arr[mid] > val:
            R = mid -1
        elif arr[mid] < val:
            L = mid +1
        else:
            return 1
    return 0

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

log(("arr", arr))

M = int(sys.stdin.readline())
t_arr = list(map(int, sys.stdin.readline().split()))

arr = sorted(arr)

for i in range(M):
    sys.stdout.write(f"{binary_search(t_arr[i])} ")