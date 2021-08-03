import sys
DEBUG = True


def log(message):
    if DEBUG:
        print(message)


N, ke = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().rstrip().split()))

def binary_search(ke):
    L = 0
    R = max(arr)
    ans=0
    while L<=R:
        next_div = (L+R)//2
        su = 0
        for i in arr:
            if i > next_div:
                su += i - next_div
        # 나무가 딱 맞게 잘라지지 않고 남게 잘라질 경우가 존재하기 때문에
        # su == ke로 조건을 잡으면 Fail이 나게 됨
        if su >= ke:
            ans = next_div
            L = next_div+1
        elif su < ke:
            R = next_div-1
        # else:
    return ans

def binary_search2(ke):
    L = 0
    R = max(arr)
    ans=0
    while L<R:
        next_div = (L+R)//2
        su = 0
        for i in arr:
            if i > next_div:
                su += i - next_div
        # 나무가 딱 맞게 잘라지지 않고 남게 잘라질 경우가 존재하기 때문에
        # su == ke로 조건을 잡으면 Fail이 나게 됨
        if su >= ke:
            ans = next_div
            L = next_div+1
        elif su < ke:
            R = next_div
        # else:
    return ans

def binary_search3(ke):
    L = 0
    R = max(arr)
    ans=0
    while L<R:
        next_div = (L+R)//2
        su = 0
        for i in arr:
            if i > next_div:
                su += i - next_div
        # 나무가 딱 맞게 잘라지지 않고 남게 잘라질 경우가 존재하기 때문에
        # su == ke로 조건을 잡으면 Fail이 나게 됨
        if su >= ke:
            # ans = next_div
            L = next_div+1
        elif su < ke:
            R = next_div
        # else:
    return R-1


sys.stdout.write(f"{binary_search3(ke)}\n")


