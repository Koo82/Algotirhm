import sys
DEBUG = True

def log(message):
    if DEBUG:
        print(message)


def binary_search_leftmost(val):
    L = 0
    R = N

    while L<R:
        mid = (L+R)//2
        if arr[mid] < val:
            L = mid+1
        else:  # arr[mid] >= val
            R = mid
    if L < N and arr[L] == val:
        return L
    return -10


def binary_search_rightmost(val):
    L = 0
    R = N

    while L < R:
        mid = (L + R) // 2
        if arr[mid] > val:
            R = mid
        else:  # arr[mid] <= val
            L = mid +1
    if L>0 and arr[R-1] == val:
        return R-1
    return -10

def binary_search_leftmost2(val):
    L = 0
    R = N-1
    ans = -1
    while L<=R:
        mid = (L+R)//2
        if arr[mid] < val:
            L = mid + 1
        elif arr[mid] > val:  # arr[mid] >= val
            R = mid - 1
        else:
            R = mid -1
            ans = mid

    return ans


def binary_search_rightmost2(val):
    L = 0
    R = N-1
    ans = -1
    while L <= R:
        mid = (L + R) // 2
        if arr[mid] > val:
            R = mid -1
        elif arr[mid] < val:
            L = mid +1
        else:
            ans = mid
            L = mid +1
    return ans


N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

log(("arr", arr))

M = int(sys.stdin.readline())
t_arr = list(map(int, sys.stdin.readline().split()))

arr = sorted(arr)

# print(binary_search_rightmost(t_arr[0]))

for i in range(M):
    l = binary_search_leftmost2(t_arr[i])
    r = binary_search_rightmost2(t_arr[i])
    log((l,r))
    if l == -1 or r == -1:
        sys.stdout.write(f"0 ")

    else:
        sys.stdout.write(f"{r - l + 1} ")