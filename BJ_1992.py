# 알문해전 에서 나온 쿼드 트리 문제가 백준에도 나왔다.
# 이 문제를 처음 봤다면 내가 어떻게 해결할 수 있었을까? 분할정복 문제인 것은 알았을까?
# 약간의 디테일이 다르지만, 눈으로만 본 문제를 한번 코딩해 보자
# 성공! 실제 사진 map을 보고 압축하는 문제는 크게 어렵지 않게 코딩 가능함


import sys
DEBUG=True


def log(message):
    if DEBUG:
        print(message)

def size_check(y,x,size):
    t_sum = 0
    for yp in range(y,y+size):
        t_sum += sum(arr[yp][x:x+size])
    if t_sum == size*size:
        sys.stdout.write("1")
        return 0
    elif t_sum == 0:
        sys.stdout.write("0")
        return 0
    else:
        return 1


def quadtree(y, x, size):

    if size_check(y,x,size):
        sys.stdout.write("(")
        quadtree(y,x,size//2)
        quadtree(y,x+size//2, size//2)
        quadtree(y+size//2, x, size//2)
        quadtree(y+size//2, x+size//2, size//2)
        sys.stdout.write(")")
    # else:
    #     if size == N:


N = int(sys.stdin.readline())
arr = []
for _ in range(N):
    arr.append(list(map(int, list(sys.stdin.readline().strip()))))

log(("arr: ", arr))
# sys.stdout.write("(")
quadtree(0,0,N)
# sys.stdout.write(")")