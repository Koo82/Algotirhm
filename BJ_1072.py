# 접근 방법 key: 숫자의 범위가 넓어 이분 탐색이 적절하다고 판단
# 어려웠던 점: R, 즉 max_bound를 어떻게 처리해야 할지 고심.
#             이럴 때는 최악의 케이스를 생각하면 됨. 즉 X가 10억이고 98%의 경우 10억번이 필요
#             하지만, 나의 경우는 R_max를 거듭제곱 차수를 올려가며 곱해서 max_bound 탐색
#             99% 이상에서는 아무리 숫자를 더해도 100%가 되지 못하는데, 난 L==R만 고려하여 20% 지점에서 fail


import sys
DEBUG = True


def log(message):
    if DEBUG:
        print(message)


X, Y = map(int, sys.stdin.readline().split())

# if X == Y:

def percent(s,t):
    return (s*100) // t

def max_bound(val):
    bound = X
    mul = 1
    while percent(Y + bound, X + bound) < val:
        mul += 1
        bound = X ** mul
    log(bound)
    return bound


def binary_search(val):
    L = Y
    R = X
    diff = R-L
    if L >= R-R//100:
        return L-1
    ans = 0

    R_max = R + max_bound(val)
    log(R_max)
    while L <= R_max:
        mid = (L+R_max) // 2
        if percent(mid, mid+diff) >= val+1:
            log(("mid-L+R", mid-L+R))
            log(("percent",percent(mid, mid+diff)))
            ans = mid
            log(("ans", ans))
            R_max = mid -1
        else:
            L = mid +1

    return ans



cur_val = percent(Y, X)

log(cur_val)

sys.stdout.write(f"{binary_search(cur_val)-Y}")