import sys
DEBUG = True

# Don't think too deeply and make it simple as possible
def log(message):
    if DEBUG:
        print(message)


def lower_count(val):
    cnt = 0
    for i in range(1,N+1):
        cnt += min(N, val//i)
    return cnt


def binary_search(val):
    L = 1
    R = N*N
    ans = 0
    while L<=R:
        mid = (L+R) // 2
        if lower_count(mid) >= val:
            ans = mid
            R = mid -1
        else:
            L = mid +1
    return ans

N = int(sys.stdin.readline())
k = int(sys.stdin.readline())


sys.stdout.write(f"{binary_search(k)}")

